#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define null NULL

class node{
    public:
    node*left;
    node*right;
    int val;
    node(int d = 0){
        left= right = null;
        val = d;
    }
};

class trie{
    private:
    node *root;
    public:
    trie(){
        root = new node(0);
    }

    void insert(int x, int xorSoFar){
        node*temp = root;
        for(int i = 31;i>=0;i--){
            bool b = xorSoFar & (1<<i);
            
            if(!b){
                if(temp->left == null){
                    temp->left= new node();
                }
                temp = temp->left;
            }
            else{
                if(temp->right == null){
                    temp->right = new node();
                }
                temp = temp->right;
            }
        }
        temp->val = xorSoFar;
    }

    int query(int xorSoFar){
        node*temp = root;
        for(int i =31;i>=0;i--){
            bool b = xorSoFar & (1<<i);

            if(b == 0){
                if(temp->right!= null){
                    temp = temp->right;
                }
                else if(temp->left!= null){
                    temp = temp->left;
                }
            }
            else{
                 if (temp->left != NULL)
                {
                    temp = temp->left;
                }
                else if (temp->right != NULL)
                {
                    temp = temp->right;
                }
            }
        }
        return xorSoFar ^ (temp->val);
    }
    
};


int main()
{
    trie t;
    int n;
    cin>>n;
    
    int xorSoFar = 0;
    int result = 0;
    for(ll i =0;i<n;i++){
        int x;
        cin >> x;
        xorSoFar ^= x;
        t.insert(x, xorSoFar);
        result = max(result, t.query(xorSoFar));

    }
    return 0;
}