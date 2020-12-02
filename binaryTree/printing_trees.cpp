#include<iostream>
#include<fstream>
using namespace std;

class node{
    public:
        int data;
        node*left;
        node*right;
        node(int d){
            data = d;
            left = NULL;
            right = NULL;
        }
};

node *buildTree(){  
    int d;
    cin>>d;

    if(d ==-1)
        return NULL;

    node *root = new node(d);
    root->left = buildTree();
    root->right = buildTree();

    return root;
}

// preorder_print
void preorder_print(node*root){
    if(root == NULL)
        return;

    cout<<root->data<<" ";
    preorder_print(root->left);
    preorder_print(root->right);
}


// inorder_print
void inorder_print(node * root){
    if(root == NULL)
        return;
    
    // left root first
    inorder_print(root->left);
    // root node
    cout<<root->data<<" ";
    //right node
    inorder_print(root->right);
}


// postorder_print
void postorder_print(node * root){
    if(root == NULL)
        return;
    
    // left root first
    postorder_print(root->left);
    //right node
    postorder_print(root->right);
    // root node
    cout<<root->data<<" ";
}

int height(node*root){
    if(root ==NULL){
        return 0;
    }

    int ls = height(root->left);
    int rs = height(root->right);

    return max(ls, rs)+1;
}

// levelWise_print



int main(){

    node*root = buildTree();
    preorder_print(root);

    cout<<endl;

    inorder_print(root);

    cout<<endl;

    postorder_print(root);

    cout<<endl;

    cout<<height(root);

    return 0;
}