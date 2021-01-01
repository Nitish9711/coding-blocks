#include <bits/stdc++.h>
using namespace std;
#define null NULL
// binary search tree
// left->data < root->data<right->data

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        data = d;
        left = null;
        right = null;
    }
};

node *insertInBST(node *root, int data)
{
    if (root == null)
    {
        return new node(data);
    }

    if (data <= root->data)
    {
        root->left = insertInBST(root->left, data);
    }
    else
    {
        root->right = insertInBST(root->right, data);
    }
    return root;
}

node *build()
{
    int d;
    cin >> d;
    if (d == -1)
    {
        return null;
    }
    node *root = null;
    while (d != -1)
    {
        root = insertInBST(root, d);
        cin >> d;
    }
    return root;
}

void bfs_other(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(null);
    while (!q.empty())
    {
        node *f = q.front();
        if (f == null)
        {
            cout << endl;
            q.pop();
            if (!q.empty())
            {
                q.push(null);
            }
        }
        else
        {
            cout << f->data << " ";
            q.pop();
            if (f->left)
                q.push(f->left);
            if (f->right)
                q.push(f->right);
        }
    }
    return;
}

void inorder(node *root)
{
    if (root == null)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// search
// time complexity
// o(log n) <= o(h)<= o(n);

bool search(node *root, int d)
{
    if (root == null)
        return false;

    if (root->data == d)
    {
        return true;
    }

    if (d <= root->data)
        return search(root->left, d);

    else
    {
        return search(root->right, d);
    }
}

// deletion
node *deleteInBST(node *root, int data)
{
    if (root == null)
    {
        return null;
    }
    else if (data < root->data)
    {
        root->left = deleteInBST(root->left, data);
        return root;
    }
    else if (data == root->data)
    {

        // node with 0 child
        if (root->left == null && root->right == null)
        {
            delete root;
            return null;
        }
        // node with 1 child
        if (root->left != null && root->right == null)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }
        if (root->right != null && root->left == null)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }

        // node with 2 child
        node*replace = root->right;
        while (replace->left != null)
        {
            replace = replace->left;
        }
        root->data = replace->data;
        root->right = deleteInBST(root->right, replace->data);
        return root;
        

    }
    else
    {
        root->right = deleteInBST(root->right, data);
        return root;
    }
}


bool checkBST(node *root , int minV = INT_MIN, int maxV = INT_MAX){
    if(root == null)
        return true;

    if(root->data >= minV && root->data <= maxV && checkBST(root->left, minV, root->data) && checkBST(root->right, root->data, maxV)){
        return true;
    }

    return false;

}


// convert a tree into linked list
class LinkedList{
    public:
        node*head;
        node*tail;
};

LinkedList flatten(node*root){
    LinkedList l;
    if(root == null){
        l.head = l.tail = null;
        return l;
    }
    if(root->left == null && root->right == null){
        l.head  = l.tail = root;
        return l;
    }
    if(root->left != null && root->right == null){
        LinkedList leftLL = flatten (root->left);
        leftLL.tail ->right = root;
        l.head = leftLL.head;
        l.tail = root;
        return l;
    }
    if(root->left == null && root->right != null){
        LinkedList rightLL = flatten (root->right);
        root->right = rightLL.head;
        l.head = root;
        l.tail = rightLL.tail;
        return l;
    }
    
    LinkedList leftLL = flatten(root->left);
    LinkedList rightLL = flatten(root->right);

    leftLL.tail->right = root;
    root->right = rightLL.head;

    l.head = leftLL.head;
    l.tail = rightLL.tail;

    return l;

}





int main()
{
    node *root = build();
    // bfs_other(root);
    cout << endl;
    // inorder(root);
    // int data;
    // cin >> data;
    // if (search(root, data))
    // {
    //     cout << "present" << endl;
    // }
    // else
    // {
    //     cout << "not present" << endl;
    // }
    // int s;
    // cin>>s;
    // root = deleteInBST(root, s);
    // // bfs_other(root);
    // inorder(root);
    //  if (checkBST(root))
    // {
    //     cout << "bst" << endl;
    // }
    // else
    // {
    //     cout << "not bst" << endl;
    // }
    LinkedList l = flatten (root);
    node *temp = l.head;

    while (temp!= null){
        cout<<temp->data<< " ->";
        temp = temp->right;
    }
   
    

    return 0;
}