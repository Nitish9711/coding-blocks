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


// convert a tree into linked list inorder 
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

//post order
//recursive //singly linked list
#define TreeNode node
  void flatten(TreeNode* A) {
         if(!A || (!A->left && !A->right))
    return;
    if(A->left) {
    flatten(A->left);
    TreeNode* temp = A->right;
    A->right = A->left;
    A->left = NULL;
    TreeNode* t = A->right;
    while(t->right)
    t = t->right;
    t->right = temp;
    }
    flatten(A->right);
    }

// void flatten(TreeNode* root) {
//         node *cur =root;
//         while(cur!= null){
//             if(cur->left!= null){
//                 if(cur->right != null){
//                     node *next = cur->left;
//                     while(next->right != null){
//                         next  = next->right;
                        
//                     }
//                     next->right = cur->right;
//                 }
//                 cur->right = cur->left;
//                 cur->left = null;
//             }
//             cur = cur->right;
//         }
//     }

// doubly linked list
// Changes left pointers to work as
// previous pointers in converted DLL
// The function simply does inorder
// traversal of Binary Tree and updates
// left pointer using previously visited node
void fixPrevPtr(node *root)
{
    static node *pre = NULL;
 
    if (root != NULL)
    {
        fixPrevPtr(root->left);
        root->left = pre;
        pre = root;
        fixPrevPtr(root->right);
    }
}
 
// Changes right pointers to work
// as next pointers in converted DLL
node *fixNextPtr(node *root)
{
    node *prev = NULL;
 
    // Find the right most node
    // in BT or last node in DLL
    while (root && root->right != NULL)
        root = root->right;
 
    // Start from the rightmost node,
    // traverse back using left pointers.
    // While traversing, change right pointer of nodes.
    while (root && root->left != NULL)
    {
        prev = root;
        root = root->left;
        root->right = prev;
    }
 
    // The leftmost node is head
    // of linked list, return it
    return (root);
}
 
// The main function that converts
// BST to DLL and returns head of DLL
node *BTToDLL(node *root)
{
    // Set the previous pointer
    fixPrevPtr(root);
 
    // Set the next pointer and return head of DLL
    return fixNextPtr(root);
}

/// method 2
void BinaryTree2DoubleLinkedList(node *root, node **head)
{
    // Base case
    if (root == NULL) return;
 
    // Initialize previously visited node as NULL. This is
    // static so that the same value is accessible in all recursive
    // calls
    static node* prev = NULL;
 
    // Recursively convert left subtree
    BinaryTree2DoubleLinkedList(root->left, head);
 
    // Now convert this node
    if (prev == NULL)
        *head = root;
    else
    {
        root->left = prev;
        prev->right = root;
    }
    prev = root;
 
    // Finally convert right subtree
    BinaryTree2DoubleLinkedList(root->right, head);
}
// function to find largest value less then N
int findMaxforN(Node* root, int N)
{
    // Base cases
    if (root == NULL)
        return -1;
    if (root->key == N)
        return N;
 
    // If root's value is smaller, try in right
    // subtree
    else if (root->key < N) {
        int k = findMaxforN(root->right, N);
        if (k == -1)
            return root->key;
        else
            return k;
    }
 
    // If root's key is greater, return value
    // from left subtree.
    else if (root->key > N)
        return findMaxforN(root->left, N);   
}

// pair sum O(n) time O(n) space
bool findpairUtil(Node* root, int sum,
                  unordered_set<int>& set)
{
    if (root == NULL)
        return false;
 
    if (findpairUtil(root->left, sum, set))
        return true;
 
    if (set.find(sum - root->data) != set.end()) {
        cout << "Pair is found (" << sum - root->data
             << ", " << root->data << ")" << endl;
        return true;
    }
    else
        set.insert(root->data);
 
    return findpairUtil(root->right, sum, set);
}



// Returns true if a pair with target
// sum exists in BST, otherwise false O (logn)
 // root : the root Node of the given BST
    // target : the target sum
    int isPairPresent(struct Node *root, int target)
    {
        if(!root) return false;
    
    stack<node*> s1, s2;
    node* temp1 = root;
    node* temp2 = root;
    
    
    while(1)
    {
        while(temp1)
        {
            s1.push(temp1);
            temp1 = temp1->left;
        }
        
        while(temp2)
        {
            s2.push(temp2);
            temp2 = temp2->right;
        }
        
        if(s1.empty() || s2.empty()) break;
        
        temp1 = s1.top();
        temp2 = s2.top();
        
        if((temp1->val + temp2->val) == target)
        {
            if(temp1 == temp2) return false;
            
            return true;
        }
        
        else if((temp1->val + temp2->val) < target)
        {
            s1.pop();
            temp1 = temp1->right;
            temp2 = NULL;
        }
        else
        {
            s2.pop();
            temp2 = temp2->left;
            temp1 = NULL;
        }
    }
    
    return false;
    }




// Helper function to find minimum value node in a given BST
Node* findMinimum(Node* root)
{
    while (root->left) {
        root = root->left;
    }
 
    return root;
}
 
// Recursive function to find an inorder successor for the given key in a BST.
// Note that successor `succ` is passed by reference to the function
void findSuccessor(Node* root, Node*& succ, int key)
{
    // base case
    if (root == nullptr)
    {
        succ = nullptr;
        return;
    }
 
    // if a node with the desired value is found, the successor is the minimum value
    // node in its right subtree (if any)
    if (root->data == key)
    {
        if (root->right) {
            succ = findMinimum(root->right);
        }
    }
    // if the given key is less than the root node, recur for the left subtree
    else if (key < root->data)
    {
        // update successor to the current node before recursing in the left subtree
        succ = root;
        findSuccessor(root->left, succ, key);
    }
 
    // if the given key is more than the root node, recur for the right subtree
    else {
        findSuccessor(root->right, succ, key);
    }
}


// / Function to truncate the BST and remove nodes having keys
// outside the valid range
Node* truncate(Node* root, int min, int max)
{
    // base case
    if (root == nullptr) {
        return root;
    }
 
    // recursively truncate the left and right subtree first
    root->left = truncate(root->left, min, max);
    root->right = truncate(root->right, min, max);
 
    Node* curr = root;
 
    // if the root's key is smaller than the minimum allowed, delete it
    if (root->data < min)
    {
        root = root->right;
        delete curr;
    }
    // if the root's key is larger than the maximum allowed, delete it
    else if (root->data > max)
    {
        root = root->left;
        delete curr;
    }
 
    return root;
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
    // LinkedList l = flatten (root);
    // node *temp = l.head;

    // while (temp!= null){
        // cout<<temp->data<< " ->";
        // temp = temp->right;
    }
   
    

    return 0;
}