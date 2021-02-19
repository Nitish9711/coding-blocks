#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define null NULL


class node{
    public:
    char data;
    unordered_map<char, node*> children;
    int cnt;
    bool terminal;
    node(char d){
        data= d;
        terminal = false;
        cnt = 0;
    }
};

class Trie{
    node *root;
    // int cnt;
    public:
        Trie(){
            root = new node('\0');
           
        }

      void insert(string w){
          node *temp = root;
          for(int i =0;i<w.length(); i++){
              char ch = w[i];
              if(temp->children.count(ch)){
                  temp = temp->children[ch];
                  temp->cnt = temp->cnt + 1;
              }
              else{
                  node *n = new node(ch);
                  temp->children[ch] = n;
                  temp = n;
                  temp->cnt = temp->cnt + 1;
              }
          }
          temp->terminal = true;
        }  

        string prefix(string s){
            node *temp = root;
            int i =0, length= s.length();
            string ans = "";
            while(i!= length){
                if((temp->children[s[i]])->cnt == 1){
                    ans += s[i];
                    return ans;
                }
                else{
                    ans += s[i];
                    temp = temp->children[s[i]];
                }
                i++;
            }
            return ans;
        }
       
};



int main()
{
    Trie t;
   string arr[] = {"zebra", "dog", "duck", "dove"}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    
    for(int i =0;i<n;i++){
        t.insert(arr[i]);
    }


    for(int i =0;i<n;i++){
        cout<<t.prefix(arr[i])<<endl;
    }

    
    return 0;
}