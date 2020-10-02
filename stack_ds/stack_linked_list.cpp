#include<iostream>
#include<limits.h>

using namespace std;

class node{
    public:
    int data;
    node * next;
    node(int d){
        data = d;
        next= NULL;
    }
};

int isEmpty(node *root){
    return !root;
}

void push(node *&root, int d){
    node* n = new node(d);
    n->next = root;
    root = n;
    cout<<d<<" pushed to stack \n";
}

void pop(node*&root){
    if(isEmpty(root))
    {
        cout<<"nothing to pop\n";
        return;
    }
    node*temp = root;
    root = root->next;
    cout<<temp->data <<" has been removed"<<endl;
    delete temp;
}

int peek(node*root){
    if(isEmpty(root)){
        cout<<"stack is empty\n";
    }
    return root->data;
}
void print(node*root){
    while (root!=NULL)
    {
        cout<<root->data<<" ->";
        root =root->next;
    }
    cout<<endl;
    
}


int main(){
    node* root = NULL;
    push(root, 10);
    push(root, 20);
    push(root, 30);
    print(root);

    pop(root);
    print(root);
    cout<<peek(root)<<endl;

    if(isEmpty(root))
        cout<<"empty stack\n";
    else
        cout<<" not empty stack\n";

    return 0;
}