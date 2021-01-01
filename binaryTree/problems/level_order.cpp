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
    if(s == "true"){
        int d;
        cin>>d;
        node *root =new node(d);
        string l;
        cin>>l;
        if(l == "true"){
            root->left = buildTree(l);
        }
        string r;
        cin>>r;
        if(r == "true"){
            root->right = buildTree(r);
        }
        return root;
    }

    return null;
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

void ZigZagPrint(node *root){
    if(root == null)
        return;
    
    stack<node*>currentLvl;
    stack<node*>nextLvl;
    currentLvl.push(root);
    bool leftToRight = true;
    while (!currentLvl.empty())
    {
        node *temp = currentLvl.top();
        currentLvl.pop();
        if(temp != null){
            cout<<temp->data<<" ";
            if(leftToRight){
                if(temp->left)
                    nextLvl.push(temp->left);
                if(temp->right)
                    nextLvl.push(temp->right);
            }
            else{
                if(temp->right)
                    nextLvl.push(temp->right);
                if(temp->left)
                    nextLvl.push(temp->left);

            }

            if(currentLvl.empty()){
                 leftToRight = !leftToRight; 
                swap(currentLvl, nextLvl);
            }
        }

    }
       
}
int main()
{
    
    node*root = buildTree("true");
    ZigZagPrint(root);
    return 0;
}