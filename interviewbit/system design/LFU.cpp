#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define null NULL
#define vi vector<int>
#define vl vector<ll>
#define moi map<int, int>
#define umoi unordered_map<int, int>
#define mol map<ll, ll>
#define umol unordered_map<ll, ll>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define psi pair<string, int>
#define pis pair<int, string>
#define vp vector<pair<int, int>>

void ReadCP()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

class Pair{
public:
    int value, freq;
    list<int>::iterator iter;
    Pair(int value, int freq, list<int>::iterator iter){
        this->value = value;
        this->freq  = freq;
        this->iter  = iter;
    }
    
    void updateFrequency(int freq, list<int>::iterator iter){
        this->freq  = freq;
        this->iter  = iter;
    }
    
    void updateValue(int value){
        this->value = value;
    }
};

class LFUCache { 
private:
    unordered_map<int, Pair*> keys;
    unordered_map<int, list<int>> freq_and_keys; 
    
    int minFreqVal = 0, capacity = 0;
    bool flag;
    
    bool checkOriginalCacheCapacity(){
        // the following helps us understand 
        // if we are assigned a capacity of 0 for our cache
        if(flag && capacity == 0) return false;        
        
        flag = false;
        return true;
    }
    
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        this->minFreqVal = 0;
        this->flag = true;
    }
    
    int get(int key) {
        if(keys.find(key) == keys.end()) return -1;
        
        int value = keys[key]->value;
        
        // get the frequency in order to update it
        int freq = keys[key]->freq;
        
        // get the iterator of key position to delete it in our linkedlist 
        // corresponding to our previous frequency
        list<int>::iterator iter = keys[key]->iter;
        
        // delete the key at our previous frequency
        freq_and_keys[freq].erase(iter);
        
        // if there are no more keys matching the frequency in our map, erase the freqeency key
        if(freq_and_keys[minFreqVal].empty()) {
            freq_and_keys.erase(minFreqVal);
                
            // since there are no keys in our list, corresponding to freq
            // we increment our minFreqVal as our new minimum frequency value
            minFreqVal++;
        }
                
        // push our key to the front of the linked list located at our new freqeuncy key
        freq_and_keys[freq + 1].push_front(key);
         
        // update frequency and position of our key in our keys map 
        keys[key]->updateFrequency(freq + 1, freq_and_keys[freq + 1].begin());
               
        return value;
    }
    
    void put(int key, int value) {
        if(!checkOriginalCacheCapacity()) return;        
        
        if(get(key) != -1){
            keys[key]->updateValue(value);
            return;
        }   
       
        if(--capacity < 0){
            int keyVal = freq_and_keys[minFreqVal].back();

            keys.erase(keyVal);

            freq_and_keys[minFreqVal].pop_back();
                        
            capacity++;
        } 
        
        // since this is the first time, we're inserting our key, it's frequencey is 1, 
        // and thus our minimum frequency is 1     
        minFreqVal = 1;
        freq_and_keys[minFreqVal].push_front(key);       
        keys[key] = new Pair(value, minFreqVal, freq_and_keys[minFreqVal].begin());
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ReadCP();
    int t;
    cin >> t;
    while (t--)
    {
    }
    return 0;
}