#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define null NULL
#define vi vector<int>
#define vl vector<ll>
#define moi map<int, int>
#define umoi unordered_map<int, int>
#define mol map<ll, ll>
#define umol unordered_map<ll, ll>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define psi pair<string, int>
#define pis pair<int, string>
#define vp vector<pair<int, int>>
#define Node node
#define newNode node
#define key data
void ReadCP()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

class node{
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

node* buildTree(){
    int d;
    cin>>d;
    if(d == -1)
        return null;
    node *root = new node(d);
    root->left = buildTree();
    root->right = buildTree();

    return root;
}

// preOrder recursive
void prePrint(node *root){
    if(root == null){
        return;
    }
    cout<<root->data<<" ->";
    prePrint(root->left);
    prePrint(root->right);

}
// preOrder non recursive 
void prePrintNonRecursive(node *root){
    stack<node*>s;
    while(1){
        while(root != null){
            cout<<root->data<<" ->";
            s.push(root);
            root = root->left;
        }
        if(s.empty())
            break;
        root = s.top();
        s.pop();
        root = root->right;

    }
    
}

void inOrder(node *root){
    if(root == null)
        return;
    
    inOrder(root->left);
    cout<<root->data<<" ->";
    inOrder(root->right);
}

void inOrderNonRecursive(node *root){
    stack<node*>s;
    while(1){
        while(root){
            s.push(root);
            root = root->left;
        }
        if(s.empty())
            break;
        root = s.top();
        s.pop();
        cout<<root->data<<" ->";
        root = root->right;
    }
}
void postOrder(node *root){
    if(root ==  null)
        return;

    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ->";
}
void postOrderNonRecursive(node *root){
    stack<node*>s1, s2;
    node* prev = null;
    
    s1.push(root);
    while (!s1.empty())
    {
        node *temp = s1.top();
        s1.pop();
        s2.push(temp);


        if(temp->left)
            s1.push(temp->left);
        if(temp->right)
            s1.push(temp->right);
    }   
    while (!s2.empty()) {
        node *temp = s2.top();
        s2.pop();
        cout << temp->data << " ->";
    }
    
    
}
void postOrderWay2(node *root){
    stack<node*>s;
    node*prev = null;
    // s.push(root);
    do{
        while(root!= null){
            s.push(root);
            root =root->left;
        }

        while(root== null && !s.empty()){
            root = s.top();
            if(root ->right == null || root->right == prev){
                cout<<root->data<<" ->";
                s.pop();
                prev = root;
                root = null;
            }
            else 
                root = root->right;
        }

    }while(!s.empty());
}


// height of a tree()
int height(node *root){
    if(root == null)
        return 0;
    int ls= height(root->left);
    int rs = height(root->right);
    return max(ls, rs) + 1;

}

void printKthLevel(node *root, int k){
    if(root == null)
        return;

    if(k == 1)
        cout<<root->data<<" ->";
    printKthLevel(root->left, k-1);
    printKthLevel(root->right, k-1);
}
void printAllLevel(node *root){
    int h = height(root);
    for(int i= 1;i<=h;i++){
        printKthLevel(root, i);
        cout<<endl;
    }
}
void bfs(node *root){
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        node *f = q.front();
        cout<<f->data<<" ->";
        q.pop();

        if(f->left)
            q.push(f->left);
        if(f->right)
            q.push(f->right);
    }
}
void bfs_other(node *root){
    queue<node*>q;
    q.push(root);
    q.push(null);
    while(!q.empty()){
        node *f = q.front();
        if(f == null)
        {
            cout<<endl;
            q.pop();
            if(!q.empty())
                q.push(null);
        }
        else{
            cout<<f->data<<" ->";
            q.pop();
            if(f->left)
                q.push(f->left);
            if(f->right)
                q.push(f->right);
        }
    }
}
int count(node *root){
    if(root == null)
        return 0;
    return count(root->left)  + count(root->right) + 1;
}
int sum(node *root)
{
    if (root == null)
        return 0;
    return sum(root->left) + sum(root->right) + root->data;
}

//o(n) // O(h) space for call stack
int height(node* root, int& ans)
{
    if (root == NULL)
        return 0;
 
    int left_height = height(root->left, ans);
 
    int right_height = height(root->right, ans);
 
    // update the answer, because diameter of a
    // tree is nothing but maximum value of
    // (left_height + right_height + 1) for each node
    ans = max(ans, 1 + left_height + right_height);
 
    return 1 + max(left_height, right_height);
    }
 
int diameterOfBinaryTree(node* root) {
    if (root == NULL)
    return 0;
    int ans = INT_MIN; // This will store the final answer
    height(root, ans);
    return ans-1;  
}

class Diameter{
    public:
        int height;
        int diameter;

};
Diameter optimized_diameter(node *root){
    Diameter p;
    if(root == null){
        p.diameter = p.height = 0;
        return p;
    }

    Diameter left = optimized_diameter(root->left);
    Diameter right = optimized_diameter(root->right);

    p.height = max(left.height , right.height) + 1;
    p.diameter = max(left.height + right.height, max(left.diameter, right.diameter));

    return p;
}


int replaceSumWithSumofChildNodes(node *&root)
{
    if(root == null)
        return 0;

    int temp = root->data;
    root->data = replaceSumWithSumofChildNodes(root->left) + replaceSumWithSumofChildNodes(root->right);
    return temp + root->data;
}

// Recursive function to check if a given binary tree is height-balanced or not
int isHeightBalanced(Node* root, bool &isBalanced)
{
    // base case: tree is empty or not balanced
    if (root == nullptr || !isBalanced) {
        return 0;
    }
    // get the height of the left subtree
    int left_height = isHeightBalanced(root->left, isBalanced);
    // get the height of the right subtree
    int right_height = isHeightBalanced(root->right, isBalanced);
    // tree is unbalanced if the absolute difference between the height of
    // its left and right subtree is more than 1
    if (abs(left_height - right_height) > 1) {
        isBalanced = false;
    }
    // return height of subtree rooted at the current node
    return max(left_height, right_height) + 1;
}
 
// The main function to check if a given binary tree is height-balanced or not
bool isHeightBalanced(Node* root)
{
    bool isBalanced = true;
    isHeightBalanced(root, isBalanced);
 
    return isBalanced;
}
// // check tree is height balanced or not
// class HBPair{
//     public:
//     int height;
//     int balance;

// };
// HBPair isHeightBalanced(node *root){
//     HBPair p;
//     if(root == null){
//         p.height =0;
//         p.balance = true;
//         return p;
//     }

//     HBPair left, right;
//     left = isHeightBalanced(root->left);
//     right = isHeightBalanced (root->right);


//     p.height = max(left.height , right.height) + 1;
//     if(abs(left.height - right.height )<=1 && left.balance && right.balance)
//         p.balance= true;
//     else
//         p.balance = false;
//     return p;
// }

// build Height Balanced Tree
node *buildTreeFromArray(vector<int>ar, int s, int e){
    if(s >e)
        return null;
    
    int mid = (s+e)/2;
    node *root = new node(ar[mid]);
    root->left = buildTreeFromArray(ar, s, mid-1);
    root->right = buildTreeFromArray(ar,  mid +1 , e);

    return root;
}
//O(n2) creater tree from preorder
node *CreateTreeFromTrav(vector<int>in, vector<int>pre,int s, int e){
    static int i =0;
    if(s > e)
        return null;
    
    node *root = new node(pre[i]);
    int index =-1;
    for(int j =s;j<=e;j++){
        if(in[j] == pre[i])
        {
            index = j;
            break;
        }
    }
    i++;
    root->left  = CreateTreeFromTrav(in, pre, s, index-1);
    root->right = CreateTreeFromTrav(in, pre, index +1 ,e);
    return root;

}


// Recursive function to construct a binary tree from a given
// inorder and preorder sequence O(n) 
// O(n) for hashign and recursion
/* 
struct Node
{
    int key;
    Node *left, *right;
};
 
Function to create a new binary tree node having a given key
Node* newNode(int key)
{
    Node* node = new Node;
    node->key = key;
    node->left = node->right = nullptr;
 
    return node;
}
Node* construct(int start, int end, vector<int> const &preorder,
                int &pIndex, unordered_map<int, int> &map)
{
    // base case
    if (start > end) {
        return nullptr;
    }
 
    // The next element in `preorder[]` will be the root node of subtree
    // formed by sequence represented by `inorder[start, end]`
    Node *root = newNode(preorder[pIndex++]);
 
    // get the root node index in sequence `inorder[]` to determine the
    // left and right subtree boundary
    int index = map[root->key];
 
    // recursively construct the left subtree
    root->left = construct(start, index - 1, preorder, pIndex, map);
 
    // recursively construct the right subtree
    root->right = construct(index + 1, end, preorder, pIndex, map);
 
    // return current node
    return root;
}
 
Construct a binary tree from inorder and preorder traversals.
This function assumes that the input is valid
i.e., given inorder and preorder sequence forms a binary tree
Node* construct(vector<int> const &inorder, vector<int> const &preorder)
{
    // get the total number of nodes in the tree
    int n = inorder.size();
 
    // create a map to efficiently find the index of any element in
    // a given inorder sequence
    unordered_map<int, int> map;
    for (int i = 0; i < n; i++) {
        map[inorder[i]] = i;
    }
 
    // `pIndex` stores the index of the next unprocessed node in preorder;
    // start with the root node (present at 0th index)
    int pIndex = 0;
 
    return construct(0, n - 1, preorder, pIndex, map);
}
*/

void RightViewBinaryTree(node *root, int level, int &maxLevel){
    if(root == null)
        return;
    
    if(maxLevel < level){
        cout<<root->data<<endl;
        maxLevel = level;
    }

    RightViewBinaryTree(root->right, level + 1, maxLevel);
    RightViewBinaryTree(root->left,level + 1, maxLevel);

}
void LeftViewBinaryTree(node *root, int level, int &maxLevel){
    if(root == null)
        return;
    
    if(maxLevel < level){
        cout<<root->data<<endl;
        maxLevel = level;
    }

    LeftViewBinaryTree(root->left,level + 1, maxLevel);
    LeftViewBinaryTree(root->right, level + 1, maxLevel);

}

// Recursive function to perform preorder traversal on the tree and fill the map.
// Here, the node has `dist` horizontal distance from the tree's root,
// and the `level` represents the node's level.
// use unordred map
 void printBottom(Node* node, int dist, int level, auto &map)
{
    // base case: empty tree
    if (node == nullptr) {
        return;
    }
 
    // if the current level is more than or equal to the maximum level seen so far
    // for the same horizontal distance or horizontal distance is seen for
    // the first time, update the map
 
    if (level >= map[dist].second)
    {
        // update value and level for the current distance
        map[dist] = { node->key, level };
    }
 
    // recur for the left subtree by decreasing horizontal distance and
    // increasing level by 1
    printBottom(node->left, dist - 1, level + 1, map);
 
    // recur for the right subtree by increasing both level and
    // horizontal distance by 1
    printBottom(node->right, dist + 1, level + 1, map);
}
 

// Function to print the bottom view of a given binary tree
void printBottom(Node* root)
{
    // create an empty map where
    // `key` —> relative horizontal distance of the node from the root node, and
    // `value` —> pair containing the node's value and its level
 
    map<int, pair<int, int>> map;
 
    // perform preorder traversal on the tree and fill the map
    printBottom(root, 0, 0, map);
 
    // traverse the map and print the bottom view
    for (auto it: map) {
        cout << it.second.first << " ";
    }
}


// Recursive function to perform preorder traversal on the tree and fill the map.
// Here, the node has `dist` horizontal distance from the tree's root,
// and the level represents the node's level.
void printTop(Node* root, int dist, int level, map<int, pair<int, int>> &map)
{
    // base case: empty tree
    if (root == nullptr) {
        return;
    }
 
    // if the current level is less than the maximum level seen so far
    // for the same horizontal distance, or if the horizontal distance
    // is seen for the first time, update the map
    if (map.find(dist) == map.end() || level < map[dist].second)
    {
        // update value and level for current distance
        map[dist] = { root->key, level };
    }
 
    // recur for the left subtree by decreasing horizontal distance and
    // increasing level by 1
    printTop(root->left, dist - 1, level + 1, map);
 
    // recur for the right subtree by increasing both level and
    // horizontal distance by 1
    printTop(root->right, dist + 1, level + 1, map);
}
 
// Function to print the top view of a given binary tree
void printTop(Node* root)
{
    // create an empty map where
    // `key` —> relative horizontal distance of the node from the root node, and
    // `value` —> pair containing the node's value and its level
    map<int, pair<int, int>> map;
 
    // perform preorder traversal on the tree and fill the map
    printTop(root, 0, 0, map);
 
    // traverse the map and print the top view
    for (auto it: map) {
        cout << it.second.first << " ";
    }
}

// Recursive function to perform preorder traversal on the tree and
// fill the map with diagonal elements
void printDiagonal(Node* node, int diagonal, auto &map)
{
    // base case: empty tree
    if (node == nullptr) {
        return;
    }
 
    // insert the current node into the current diagonal
    map[diagonal].push_back(node->data);
 
    // recur for the left subtree by increasing diagonal by 1
    printDiagonal(node->left, diagonal + 1, map);
 
    // recur for the right subtree with the same diagonal
    printDiagonal(node->right, diagonal, map);
}
 
// Function to print the diagonal elements of a given binary tree
void printDiagonal(Node* root)
{
    // create an empty map to store the diagonal element in every slope
    unordered_map<int, vector<int>> map;
 
    // perform preorder traversal on the tree and fill the map
    printDiagonal(root, 0, map);
 
    // traverse the map and print the diagonal elements
    int temp = 0;
 
    for (int i = 0; i < map.size(); i++)
    {
        for (int i: map[i]) {
            cout << i << ' ';
        }
        cout << endl;
    }
}



#define node TreeNode
#define data val
#define null NULL
/*
vector<vector<int> >zigzagLevelOrder(TreeNode* root) {
    bool flag = false;
    vector<vector<int>>ans;
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        int  n =q.size();
        vector<int>temp;
        while(n){
            node *f = q.front();
            q.pop();
            
            temp.push_back(f->data);
            if(f->left)
                q.push(f->left);
            if(f->right)
                q.push(f->right);
            n--;
        }
        
        if(flag){
            flag = false;
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
        }
        else{
            flag = true;
            ans.push_back(temp);
        }        
    } 
    return ans;
} */



#define null NULL
#define  val data 
#define TreeNode node 
class Solution {
public:
    map<int, list<int>>graph;
    vector<int> ans;
    void buildGraph(node *root, node *parent){
        if(root == null)
            return;
        
        if(!graph.count(root->val)){
            if(parent){
                graph[root->val].push_back(parent->val);
                graph[parent->val].push_back(root->val);
            }
        }
        buildGraph(root->left, root);
        buildGraph(root->right, root);
    }
    void bfs(node *root, int k){
        queue<int>q;
        map<int, bool>visited;
        int depth =0;
        if(k == 0)
        {
            ans.push_back(root->val);
            return;
        }
        q.push(root->val);
        while(!q.empty()){
            depth = depth+1;
            int q_size = q.size();
            for (int i=0 ; i<q_size;i++) {
                int curr_node = q.front();
                visited[curr_node] = true;
                q.pop();
                for (int neighbour :graph[curr_node]) {
                    if (! visited.count(neighbour)) {
                        if (depth == k) 
                            ans.push_back(neighbour);
                        else 
                            q.push(neighbour);
                    }
                }
            }
            if (depth == k) 
                return;
                
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        buildGraph(root, null);
        bfs(target, k);
        return ans;
    }
};


node *lca(node *root,int a, int b){
    if(root == null)
        return null;
    if (root->data == a || root->data == b)
        return root;

    node *leftans = lca(root->left, a, b);
    node *rightans = lca(root->right, a, b);

    if (leftans != null and rightans != null)
    {
        return root;
    }

    if (leftans != null)
    {
        return leftans;
    }

    return rightans;
}


// max sum path from any node to any node  difficult one
//O(n) o(h)
int findMaxPathSum(Node* node, int &result)
{
    // base case: empty tree
    if (node == nullptr) {
        return 0;
    }
 
    // find maximum path sum "starting" from the left child
    int left = findMaxPathSum(node->left, result);
 
    // find maximum path sum "starting" from the right child
    int right = findMaxPathSum(node->right, result);
 
    // Try all possible combinations to get the optimal result
    result = max(result, node->data);
    result = max(result, node->data + left);
    result = max(result, node->data + right);
    result = max(result, node->data + left + right);
 
    // return the maximum path sum "starting" from the given node
    return max(node->data, node->data + max(left, right));
}
// class Pair
// {
// public:
//     int branchSum;
//     int maxSum;
//     Pair()
//     {
//         branchSum = 0;
//         maxSum = 0;
//     }
// };

// Pair maxSumPath(node *root){
//     Pair p;
//     if(root == null)
//         return p;

//     Pair left = maxSumPath(root->left);
//     Pair right = maxSumPath (root->right);

//     int op1 = root->data;
//     int op2 = left.branchSum + root->data;
//     int op3 = right.branchSum + root->data;
//     int op4 = left.branchSum + right.branchSum + root->data;

//     int current_ans = max(op1,max(op2, max(op3, op4)));
//     p.branchSum = max(left.branchSum , max(right.branchSum , 0)) + root->data;
//     p.maxSum = max(left.maxSum , max(right.maxSum , 0)) + root->data;
//     return p;
// }


// Recursive function to find the maximum sum path between two leaves
// in a binary tree
int findMaxSumPath(Node* root, int &max_sum)
{
    // base case: empty tree
    if (root == nullptr) {
        return 0;
    }
 
    // find the maximum sum node-to-leaf path starting from the left child
    int left = findMaxSumPath(root->left, max_sum);
 
    // find the maximum sum node-to-leaf path starting from the right child
    int right = findMaxSumPath(root->right, max_sum);
 
    // it is important to return the maximum sum node-to-leaf path starting from the
    // current node
 
    // case 1: left child is null
    if (root->left == nullptr) {
        return right + root->data;
    }
 
    // case 2: right child is null
    if (root->right == nullptr) {
        return left + root->data;
    }
 
    // find the maximum sum path "through" the current node
    int cur_sum = left + right + root->data;
 
    // update the maximum sum path found so far (Note that maximum sum path
    // "excluding" the current node in the subtree rooted at the current node
    // is already updated as we are doing postorder traversal)
 
    max_sum = max(cur_sum, max_sum);
 
    // case 3: both left and right child exists
    return max(left, right) + root->data;
}


// shortest distance between 2 nodes
// finding the level of given level
//O(n)// O(h)
int search(node *root, int key, int level)
{
    if (root == null)
    {
        return -1;
    }

    if (root->data == key)
    {
        return level;
    }

    int left = search(root->left, key, level + 1);

    if (left != -1)
        return left;

    return search(root->right, key, level + 1);
}

int findDistance(node *root, int a, int b)
{

    node *lca_node = lca(root, a, b);
    int l1 = search(lca_node, a, 0);

    int l2 = search(lca_node, b, 0);

    return l1 + l2;
}

#define node TreeNode
#define data val
#define null NULL
vector<vector<int> >zigzagLevelOrder(TreeNode* root) {
    bool flag = false;
    vector<vector<int>>ans;
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        int  n =q.size();
        vector<int>temp;
        while(n){
            node *f = q.front();
            q.pop();
            
            temp.push_back(f->data);
            if(f->left)
                q.push(f->left);
            if(f->right)
                q.push(f->right);
            n--;
        }
        
        if(flag){
            flag = false;
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
        }
        else{
            flag = true;
            ans.push_back(temp);
        }
        
        
        
        
        
    }
    
    return ans;
}

// Recursive function to perform preorder traversal on the tree and fill the map.
// Here, the node has `dist` horizontal distance from the tree's root
void printVertical(Node* node, int dist, auto &map)
{
    // base case: empty tree
    if (node == nullptr) {
        return;
    }
 
    // insert nodes present at a current horizontal distance into the map
    map.insert(make_pair(dist, node->data));
 
    // recur for the left subtree by decreasing horizontal distance by 1
    printVertical(node->left, dist - 1, map);
 
    // recur for the right subtree by increasing horizontal distance by 1
    printVertical(node->right, dist + 1, map);
}
 
// Function to perform vertical traversal on a given binary tree
void printVertical(Node* root)
{
    // create an empty map where
    // `key` —> relative horizontal distance of the node from the root node, and
    // `value` —> nodes present at the same horizontal distance
    multimap<int, int> map;
 
    /* We can also use `map<int, vector<int>>` instead of `multimap<int, int>` */
 
    // perform preorder traversal on the tree and fill the map
    printVertical(root, 0, map);
 
    // traverse the map and print the vertical nodes
    int temp = 0;
    for (auto it = map.begin(); it != map.end(); it++)
    {
        if (temp != it->first)
        {
            cout << endl;
            temp = it->first;
        }
        cout << it->second << " ";
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ReadCP();
    node *root = buildTree();
    prePrint(root);
    cout<<endl;
    prePrintNonRecursive(root);
    cout<<endl;
    inOrder(root);
    cout<<endl;
    inOrderNonRecursive(root);
    cout<<endl;
    postOrder(root);
    cout<<endl;
    postOrderNonRecursive(root);
    cout<<endl;
    postOrderWay2(root);
    cout<<endl;
    cout<<height(root)<<endl;
    printKthLevel(root, 1);
    cout<<endl;
    printKthLevel(root, 2);
    cout<<endl;
    printKthLevel(root, 3);
    cout<<endl;
    printAllLevel(root);
    // cout<<endl;
    bfs(root);
    cout<<endl;
    bfs_other(root);
    cout<<endl;
    // cout<<count(root)<<endl;
    // cout<<diameter(root)<<endl;
    // cout<<optimized_diameter(root).diameter<<endl;
    // replaceSumWithSumofChildNodes(root);
    bfs_other(root);
    // cout<<isHeightBalanced(root).balance <<endl;
    // root = buildTreeFromArray({1, 2, 3, 4, 5, 6, 7}, 0, 6);
    // bfs_other(root);
    int max_level = -1;
    // RightViewBinaryTree(root, 0, max_level);
    LeftViewBinaryTree(root, 0, max_level);
    return 0;
}