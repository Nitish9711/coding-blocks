#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define null NULL

class node
{
public:
    char data;
    unordered_map<char, node*> children;
    int cnt;
    bool terminal;
    node(char d)
    {
        data = d;
        terminal = false;
        cnt = 0;
    }
};

class trie
{
    node *root;

public:
    trie()
    {
        root = new node('\0');
    }

    void insert(string w)
    {
        node *temp = root;
        for (ll i = 0; i < w.size(); i++)
        {
            char ch = w[i];
            if (temp->children.count(ch))
            {
                temp = temp->children[ch];
                temp->cnt++;
            }
            else
            {
                node *n = new node(ch);
                temp->children[ch] = n;
                temp = n;
                temp->cnt++;
            }
        }

        temp->terminal = true;
    }

    bool findtemp(string s)
    {
        node *temp = root;
        for (int i = 0; s[i] != '\0'; i++)
        {
            char ch = s[i];
            if (temp->children.count(ch) == 1)
            {
                temp = temp->children[ch];
            }
            else
            {
                return false;
            }
        }

        vector<string> v;
        print(s, v, temp);
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << endl;
        }
        return true;
    }
    
    void print(string s, vector<string>&v, node* temp){
         if(temp->terminal){
        v.push_back(s);
        }

        for(auto it = temp->children.begin(); it!= temp->children.end();it++){
            s+= it->second->data;
            print(s, v, it->second);
            s.pop_back();
        }

    }
    
};

int main()
{

    trie t;
    ll n;
    cin >> n;
    string s;
    for (ll i = 0; i < n; i++)
    {   
        cin>>s;
        t.insert(s);
    }

    ll q;
    cin>>q;
    for(ll i =0;i<q;i++){
        cin>>s;
           bool temp=t.findtemp(s);
        if(!temp){
            cout<<"No suggestions"<<endl;
            t.insert(s);
        }
    }
    return 0;
}