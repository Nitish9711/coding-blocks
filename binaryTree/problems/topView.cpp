#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define null NULL

class node{
    public:
    int data;
    node *left;
    node*right;
    node(int d){
        data =d;
        left = null;
        right = null;

    }
};

node *buildTree(string s){
    
}

void bfs(node *root){

    if(root == null){
        return;
    }
    queue<node *>q;
    q.push(root);
    q.push(null);
    while (!q.empty())
    {
        node *f = q.front();
        if(f == null){
            cout<<endl;
            q.pop();
            if(!q.empty()){
                q.push(null);
            }
        }
        else{
            cout<<f->data<<" ";
            q.pop();
            if(f->left)
                q.push(f->left);
            if(f->right)
                q.push(f->right);
        }
    }
    
}
int main()
{
    
    node*root = buildTree("true");
    bfs(root);
    return 0;
}