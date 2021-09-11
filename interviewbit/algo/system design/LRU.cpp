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
class node
{
    public:
    int data;
    int key;
    node *next;
    node *prev;
    
    node(int k=0, int d=0): key(k), data(d), next(NULL), prev(NULL)
    {}
};


class LRUCache {
    unordered_map<int, node*> u;
    int cap;
    node *head;
    node *last;
    
    void putItInFront(node *elem)
    {
        elem->next = head->next;
        head->next->prev = elem;
        
        head->next = elem;
        elem->prev = head;
        
    }
    
public:
    LRUCache(int capacity) {
        cap  = capacity;
        head = new node();
        last = new node();
        
        head->next = last;
        last->prev = head;
    }
    
    int get(int key) {
        
        if(u.find(key) == u.end())
            return -1;
        
        node *elem = u[key];
        
        //Remove it from the current list;
        elem->prev->next = elem->next;
        elem->next->prev = elem->prev;
        
        //put this key to front
        putItInFront(elem);
    
        return elem->data;
    }
    
    void put(int key, int value) {
        
        if(u.find(key) != u.end())
        {
            node *elem = u[key];
            
            //Remove it from the current list;
            elem->prev->next = elem->next;
            elem->next->prev = elem->prev;
        
            //put this key to front
            putItInFront(elem);
            
            elem->data = value;
            
            return;
        }
        
        if(u.size() == cap)
        {
            //Remove the last element;
            node *toDel = last->prev;
            toDel->prev->next = toDel->next;
            toDel->next->prev = toDel->prev;
            
            u.erase(toDel->key);
            delete toDel;
        }
        
        node *newnode = new node(key, value);
        u[key] = newnode;
        putItInFront(newnode);
        
    }
};
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