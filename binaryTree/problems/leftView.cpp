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

node *buildTree(){
   int d;
   cin>>d;

   node *root = new node(d);
   queue<node*>q;
   q.push(root);
   while (!q.empty())
   {
       node *f = q.front();
       q.pop();
       int c1 , c2;
       cin>>c1>>c2;
       if(c1 != -1){
           f->left  = new node(c1);
           q.push(f->left);
       }
       if(c2  != -1){
           f->right = new node(c2);
           q.push(f->right);
       }
       
   }
   return root;
   
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

void leftView(node *root, int curLvl, int &maxLvl){
    if(root == null)
        return;
    
    if(maxLvl < curLvl){
        cout<<root->data<<" ";
        maxLvl = curLvl;
    }

    leftView(root->left, curLvl + 1, maxLvl);
    leftView(root->right, curLvl + 1, maxLvl);
}
int main()
{
    
    node*root = buildTree();
    // bfs(root);
    int maxLvl = -1;
    leftView(root, 0, maxLvl);
    return 0;
}
