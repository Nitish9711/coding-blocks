#include <bits/stdc++.h>
using namespace std;
#define ll long long
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

void preorder(node *&root)
{
    if (root == null)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(node *root)
{
    if (root == null)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void postorder(node *root)
{
    if (root == null)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int height(node *root)
{
    if (root == null)
        return 0;

    int ls = height(root->left);
    int rs = height(root->right);
    return max(ls, rs) + 1;
}

// levelwise print
// time complexity  worst Case - o(n^2);

void printKthLevel(node *root, int k)
{
    if (root == null)
        return;

    if (k == 1)
        cout << root->data << " ";

    printKthLevel(root->left, k - 1);
    printKthLevel(root->right, k - 1);
}
void level_wise(node *root)
{
    int h = height(root);

    for (int i = 1; i <= h; i++)
    {
        printKthLevel(root, i);
        cout << endl;
    }
}

void bfs_other(node *root)
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
}

void bfs(node *root)
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
                q.push(null);
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
}

int count(node *root)
{
    if (root == null)
        return 0;
    return count(root->left) + count(root->right) + 1;
}
int sum(node *root)
{
    if (root == null)
        return 0;
    return sum(root->left) + sum(root->right) + root->data;
}

int diameter(node *root)
{

    if (root == null)
        return 0;

    int h1 = height(root->left);
    int h2 = height(root->right);

    int op1 = h1 + h2;
    int op2 = diameter(root->left);
    int op3 = diameter(root->right);

    return max(op1, max(op2, op3));
}

class DPair
{
public:
    int height;
    int diameter;
};
DPair optimized_diameter(node *root)
{

    DPair p;
    if (root == null)
    {
        p.height = p.diameter = 0;
        return p;
    }

    DPair left = optimized_diameter(root->left);
    DPair right = optimized_diameter(root->right);

    p.height = max(left.height, right.height) + 1;
    p.diameter = max(left.height + right.height, max(left.diameter, right.diameter));
    return p;
}

// replace_nodes_with_sum_of_child_nodes

int replaceNodeWithSum(node *&root)
{
    if (root == null)
        return 0;
    // if(root->left == null || root->right == null){
    //     return root->data;
    // }

    int temp = root->data;

    root->data = replaceNodeWithSum(root->left) + replaceNodeWithSum(root->right);
    return temp + root->data;
}

// check height balanced tree
class HBPair
{
public:
    int height;
    bool balance;
};

HBPair isHBT(node *root)
{
    HBPair p;
    if (root == null)
    {
        p.height = 0;
        p.balance = true;
        return p;
    }

    HBPair left = isHBT(root->left);
    HBPair right = isHBT(root->right);

    p.height = max(left.height, right.height) + 1;

    if (abs(left.height - right.height) <= 1 && left.balance && right.balance)
        p.balance = true;

    else
    {
        p.balance = false;
    }

    return p;
}

node *buildHBT(int *ar, int s, int e)
{
    if (s > e)
    {
        return null;
    }

    int mid = (s + e) / 2;
    node *root = new node(ar[mid]);
    root->left = buildHBT(ar, s, mid - 1);
    root->right = buildHBT(ar, mid + 1, e);
    return root;
}

//  if we are given only pre order and inorder then binary tree will be unique

node *buildFromOrder(int *in, int *pre, int s, int e)
{

    static int i = 0;
    if (s > e)
    {
        return null;
    }

    node *root = new node(pre[i]);
    int index = -1;
    for (int j = s; j <= e; j++)
    {
        if (in[j] == pre[i])
        {
            index = j;
            break;
        }
    }
    i++;
    root->left = buildFromOrder(in, pre, s, index - 1);
    root->right = buildFromOrder(in, pre, index + 1, e);
    return root;
}

// right view of binary tree
void rightView(node *root, int level, int &maxLevel)
{
    if (root == null)
        return;

    if (maxLevel < level)
    {
        cout << root->data << endl;
        maxLevel = level;
    }

    rightView(root->right, level + 1, maxLevel);
    rightView(root->left, level + 1, maxLevel);
}
void leftView(node *root, int level, int &maxLevel)
{
    if (root == null)
        return;

    if (maxLevel < level)
    {
        cout << root->data << endl;
        maxLevel = level;
    }

    leftView(root->left, level + 1, maxLevel);
    leftView(root->right, level + 1, maxLevel);
}

// binary tree at k distance from given target node  not able to solve
void printAtLevelK(node *root, int k)
{
    if (root == null)
        return;

    if (k == 0)
    {
        cout << root->data << endl;
        return;
    }

    printAtLevelK(root->left, k - 1);
    printAtLevelK(root->right, k - 1);
    return;
}
int printAtDistanceK(node *root, node *target, int k)
{
    if (root == null)
        return -1;

    if (root == target)
    {
        printAtLevelK(root, k);
        return 0;
    }

    int dl = printAtDistanceK(root->left, target, k);
    if (dl != -1)
    {
        if (dl + 1 == k)
        {
            cout << root->data << endl;
        }
        else
        {
            printAtLevelK(root->right, k - 2 - dl);
        }
    }
    int dr = printAtDistanceK(root->right, target, k);
    if (dr != -1)
    {
        if (dr + 1 == k)
        {
            cout << root->data << " ";
        }
        else
        {
            printAtLevelK(root->right, k - 2 - dr);
        }
        return dr + 1;
    }
    return -1;
}



// find the lowest common ancestor of given nodes
node *lca(node *root, int a, int b){
    if(root == null)
        return null;

    if(root->data == a || root->data == b)
        return root;

    node *leftans = lca(root->left, a, b);
    node *rightans = lca(root->right, a, b);

    if(leftans!= null and rightans != null){
        return root;
    }
    
    if (leftans != null)
    {
        return leftans;
    }

    return rightans;

}


// max sum path from any node to any node  difficult one
class Pair{
public:
    int branchSum;
    int maxSum;
    Pair()
    {
        branchSum = 0;
        maxSum = 0;
    }
};
Pair maxSumPath(node *root){
    Pair p;
    if (root == null)
    {
        return p;
    }
    Pair left = maxSumPath(root->left);
    Pair right = maxSumPath(root->right);

    // construct value;
    int op1 = root->data;
    int op2 = left.branchSum + root->data;
    int op3 = right.branchSum + root->data;
    int op4 = left.branchSum + right.branchSum + root->data;


    int current_ans_thorugh_root = max(op1, max(op2, max(op3, op4)));


    p.branchSum = max(left.branchSum, max(right.branchSum, 0))  + root->data;
    p.maxSum = max(left.maxSum, max(right.maxSum, current_ans_thorugh_root));

    return p;


}

// shortest distance between 2 nodes
// finding the level of given level

int search(node *root, int key, int level){

    if(root == null)
        return -1;

    if(root->data == key){
        return level;
    }

    int left = search(root->left, key, level+1);

    if(left =-1){
        return left;
    }

    return search(root->right, key, level + 1);
}

int findDistance(node *root, int a, int b){
    node *lcanode = lca(root, a, b);

    int l1 = search(lcanode, a, 0);
    int l2 = search(lcanode, b, 0);

    return l1 + l2;
}


int main()
{
    // node *root = buildTree();

    // preorder(root);
    // cout << endl;
    // inorder(root);
    // cout << endl;
    // postorder(root);
    // cout << endl;

    // cout << height(root) << endl;

    // level_wise(root);

    // bfs(root);

    // cout<<count(root)<<endl;
    // cout<<sum(root)<<endl;
    // cout<<diameter(root)<<endl;

    // DPair p = optimized_diameter(root);
    // cout<<p.height<<endl;
    // cout<<p.diameter<<endl;

    // replaceNodeWithSum(root);
    // bfs(root);

    // HBPair p = isHBT(root);
    // if(p.balance)
    //     cout<<"balance"<<endl;
    // else{
    //     cout<<"not balanced"<<endl;
    // }

    // int a[]  = {1, 2, 3, 4,5 ,6, 7};
    // int n = 7;
    // node*root = buildHBT(a, 0, 6);
    // bfs(root);

    // HBPair p = isHBT(root);
    // if(p.balance)
    //     cout<<"balance"<<endl;
    // else{
    //     cout<<"not balanced"<<endl;
    // }

    int in[] = {1, 10, 9, 6, 7, 8, 3, 13, 14};
    int pre[] = {8, 10, 1, 6, 9, 7, 3, 14, 13};
    int n = sizeof(in) / sizeof(int);

    node *root = buildFromOrder(in, pre, 0, n - 1);
    bfs(root);
    // int max_level = -1;
    // // rightView(root, 0, max_level);
    // leftView(root, 0, max_level);

    node *target = root->left->right;
    cout << root << endl;
    int k;
    cin >> k;
    printAtDistanceK(root, target, k);

    return 0;
}