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

node *insertInBST(node *root, int d){
    if(root == null){
         root = new node(d);
        return root;
    }

    if(d < root->data){
        root->left  = insertInBST(root->left, d);
    }
    else{
        root->right  = insertInBST(root->right, d);
    }

    return root;    
}

void print(node *root){
    if(root == null)
        return;

    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
}


void printInRange(node *root, int l, int r){

    if(root == null)
        return;

    if(root->data > l)
        printInRange(root->left, l, r);
    if(root->data <= r && root->data >= l){
        cout<<root->data<<" ";
        // return;
    }
    
    if(root->data < r)
        printInRange(root->right, l ,r);
}
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int d;
        node *root =null;
        for(int i=0;i<n;i++){
            cin>>d;
            root =insertInBST(root, d);
        }

        int l, r;
        cin>>l>>r;
        cout<<"# Preorder : ";
        print(root);        
        cout<<endl<<"# Nodes within range are : ";
        printInRange(root,l,r);
        cout<<endl;
    }
    
    
    return 0;
}