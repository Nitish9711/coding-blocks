/* (Use Hashing) 
The idea is to store a mapping from given tree nodes to clone tree nodes in the hashtable. 
1) Recursively traverse the given Binary and copy key-value, left pointer, and a right pointer to clone tree. 
While copying, store the mapping from the given tree node to clone the tree node in a hashtable. 

‘cloneNode’ is the currently visited node of the clone tree 
‘treeNode’ is the currently visited 
node of the given tree. 
     cloneNode->key  = treeNode->key
   cloneNode->left = treeNode->left
   cloneNode->right = treeNode->right
   map[treeNode] = cloneNode 
2) Recursively traverse both trees and set random pointers using entries from the hash table. 

   cloneNode->random = map[treeNode->random] 
*/

#include <iostream>
#include <unordered_map>
using namespace std;
 
// Data structure to store a special binary tree node with a random pointer
struct Node
{
    int data;
    Node* left, *right;
    Node* random;
 
    // Constructor
    Node(int data)
    {
        this->data = data;
        this->right = this->left = nullptr;
        this->random = nullptr;
    }
};
 
// Function to print the preorder traversal on a given binary tree
void preorder(Node* root)
{
    if (root == nullptr) {
        return;
    }
 
    // print the current node's data
    cout << root->data << " ——> (";
 
    // print left child's data
    (root->left) ? cout << root->left->data    << ", " : cout << "X" << ", ";
 
    // print the right child's data
    (root->right) ? cout << root->right->data << ", " : cout << "X" << ", ";
 
    // print the random child's data
    (root->random) ? cout << root->random->data << ")\n": cout << "X" << ")\n";
 
    // recur for the left and right subtree
    preorder(root->left);
    preorder(root->right);
}
 
// Recursive function to copy random pointers from the original binary tree
// into the cloned binary tree using the map
void updateRandomPointers(Node* root, unordered_map<Node*, Node*> &map)
{
    // base case
    if (map[root] == nullptr) {
        return;
    }
 
    // update the random pointer of the cloned node
    map[root]->random = map[root->random];
 
    // recur for the left and right subtree
    updateRandomPointers(root->left, map);
    updateRandomPointers(root->right, map);
}
 
// Recursive function to clone the data, left, and right pointers for
// each node of a binary tree into a given map
Node* cloneLeftRightPointers(Node* root, unordered_map<Node*, Node*> &map)
{
    // base case
    if (root == nullptr) {
        return nullptr;
    }
 
    // clone all fields of the root node except the random pointer
 
    // create a new node with the same data as the root node
    map[root] = new Node(root->data);
 
    // clone the left and right subtree
    map[root]->left = cloneLeftRightPointers(root->left, map);
    map[root]->right = cloneLeftRightPointers(root->right, map);
 
    // return cloned root node
    return map[root];
}
 
// The main function to clone a special binary tree having random pointers
Node* cloneSpecialBinaryTree(Node* root)
{
    // create a map to store mappings from a node to its clone
    unordered_map<Node*, Node*> map;
 
    // clone data, left, and right pointers for each node of the original
    // binary tree, and put references into the map
    cloneLeftRightPointers(root, map);
 
    // update random pointers from the original binary tree in the map
    updateRandomPointers(root, map);
 
    // return the cloned root node
    return map[root];
}
 
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
 
    root->random = root->right->left->random;
    root->left->left->random = root->right;
    root->left->right->random = root;
    root->right->left->random = root->left->left;
    root->random = root->left;
 
    cout << "Preorder traversal of the original tree:\n";
    preorder(root);
 
    Node* clone = cloneSpecialBinaryTree(root);
 
    cout << "\nPreorder traversal of the cloned tree:\n";
    preorder(clone);
 
    return 0;
}

