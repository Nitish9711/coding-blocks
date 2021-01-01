#include <iostream>
#include <queue>
using namespace std;
class node
{
public:
    int data;
    node *right;
    node *left;
    node(int d)
    {
        data = d;
        right = left = NULL;
    }
};

int sum = 0; // Global variable to store final answer

void traverseTree(node *root, int k)
{
    if (root == NULL)
    {
        return;
    }
    if (k == 0)
    {
        sum += root->data;
        return;
    }
    traverseTree(root->left, k - 1);
    traverseTree(root->right, k - 1);
}


node *buildTree(node *root)
{
    int d, n;
    cin >> d >> n;
    root = new node(d);
    if (n == 0)
    {
        return root;
    }
    else if (n == 1)
    {
        root->left = buildTree(root->left);
        return root;
    }
    else
    {
        root->left = buildTree(root->left);
        root->right = buildTree(root->right);
        return root;
    }
}

int main()
{
    node *root = NULL;
    root= buildTree(root);
    int k;
    cin >> k;
    traverseTree(root, k);
    cout << sum << endl;
    return 0;
}