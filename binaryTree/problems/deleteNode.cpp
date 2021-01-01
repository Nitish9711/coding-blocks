#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define null NULL

class node{
    public:
    int data;
    node *left;
    node *right;

    node(int d){
        data =d;
        left =null;
        right = null;
    }
};


node *insertInBST(node *root, int d){
    if(root == null)
        return new node(d);

    if(root->data >= d){
        root->left = insertInBST(root->left, d);
    }
    else{
        root->right = insertInBST(root->right, d);
    }
    return root;
}

void bfs(node *root){
    if(root == null)
        return;
    queue<node*>q;
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
        else
        {
            cout<<f->data<<" ";
            q.pop();
            if(f->left)
                q.push(f->left);
            if(f->right)
                q.push(f->right);
        }
        
    }
    

}

node *deleteInBST(node *root, int d){

     if(root==null)
        return null;

    else if(d <root->data){
        root->left = deleteInBST(root->left, d);
        return root;
    }
    else if(d== root->data){
        if(root->left== null && root->right == null){
            delete root;
            return null;
        }

        if(root->left!=null && root->right == null){
            node *temp = root->left;
            delete root;
            return temp;
        }
        if(root->left == null && root->right != null){
            node *temp  = root->right;
            delete root;
            return temp;
        }

        node *replace = root->right;
        while (replace->left!= null)
        {
            replace = replace->left;
        }
        root->data = replace->data;
        root->right = deleteInBST(root->right, replace->data);
        return root;
    }
    else{
        root->right = deleteInBST(root->right, d);
        return root;
    }
        return root;
}

void preOrder(node *root){
    if(root == null)
        return;

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
    
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
       int n, m;
       cin>>n;
       int d;

       int *a = new int[n];
       node *root = null;
       for(int i =0;i<n;i++){
           cin>>d;
           root = insertInBST(root, d);
       }
        // bfs(root);
       cin>>m;

       for(int i=0;i<m;i++){
           cin>>d;
           root = deleteInBST(root, d);
       }

        preOrder(root);
        cout<<endl;


    }
    return 0;
}