#include <bits/stdc++.h>
using namespace std;
#define null NULL

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

node *buildTree()
{

    int d;
    cin >> d;

    if (d == -1)
        return null;

    node *root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

// preorder
void print(node *root)
{
    if (root == null)
        return;

    cout << root->data << " ";
    print(root->left);
    print(root->right);
}

// inorder
void in_print(node *root)
{
    if (root == null)
        return;

    in_print(root->left);
    cout << root->data << " ";
    in_print(root->right);
}

// post order
void post_print(node *root)
{
    if (root == null)
        return;

    post_print(root->left);
    post_print(root->right);
    cout << root->data << " ";
}

int height(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int ls = height(root->left);
    int rs = height(root->right);

    return max(ls, rs) + 1;
}

void printKthLevel(node *root, int k)
{
    if (root == null)
    {
        return;
    }

    if (k == 1)
    {
        cout << root->data << " ";
    }

    printKthLevel(root->left, k - 1);
    printKthLevel(root->right, k - 1);
}

// time complexity  worst Case - o(n^2);
void print_all_level(node *root)
{
    int h = height(root);
    for (int i = 1; i <= h; i++)
    {
        printKthLevel(root, i);
        cout << endl;
    }
}

// bfs traversal
void bfs(node *root)
{
    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        node *f = q.front();
        cout << f->data << " ";
        q.pop();
        if (f->left)
            q.push(f->left);
        if (f->right)
            q.push(f->right);
    }
    return;
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

// count nodes
int count(node*root){
    if(root == null)
        return 0;
    return count(root->left) + count(root->right) + 1;
}
int sum(node*root){
    if(root == null)
        return 0;
    return sum(root->left) + sum(root->right) + root->data;
}


int main()
{

    node *root = buildTree();
    print(root);
    cout << endl;
    in_print(root);
    cout << endl;
    post_print(root);
    cout << endl;
    cout << height(root) << endl;
    int h = height(root);
    print_all_level(root);
    bfs(root);
    cout << endl;
    bfs_other(root);
    cout<<count(root)<<endl;
    cout<<sum(root)<<endl;
    return 0;
}