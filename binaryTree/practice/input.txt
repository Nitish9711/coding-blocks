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
// sum of nodes
int sum(node*root){
    if(root == null)
        return 0;
    return sum(root->left) + sum(root->right) + root->data;
}

int diameter(node*root){
    if(root == null)
        return 0;
    
    int h1 = height(root->left);
    int h2 = height (root->right);

    int op1 = h1+h2;
    int op2 = diameter(root->left);
    int op3 = diameter(root->right);

    return max(op1, max(op1, op2));
}

class Pair{
    public:
        int height;
        int diameter;
};

Pair diameter_optimized(node*root){
    Pair p;
    if(root==null){
        p.diameter = p.height = 0;
        return p;
    }

    Pair left = diameter_optimized(root->left);
    Pair right = diameter_optimized(root->right);

    p.height = max(left.height, right.height) + 1;
    p.diameter = max(left.height + right.height, max(left.diameter, right.diameter));

    return p;
}


// replace_nodes_with_sum_of_child_nodes

int replaceNodeWithSum(node* &root){
    if(root==null)
        return 0;
    if(root->left == null || root->right == null){
        return root->data;
    }

    int leftSum = replaceNodeWithSum(root->left);
    int rightSum = replaceNodeWithSum(root->right);

    int temp = root->data;
    root->data = leftSum + rightSum;
    return temp + root->data;
}




// check height balanced tree
class HBPair{
    public:
    int height;
    bool balance;
};

HBPair isHeightBalance(node *root){
    HBPair p;
    if(root == null){
        p.height = 0;
        p.balance = true;
        return p;
    }

    HBPair left = isHeightBalance(root->left);
    HBPair right = isHeightBalance(root->right);

    p.height = max(left.height, right.height) +1;

    if(abs(left.height - right.height ) <=1 && left.balance && right.balance){
        p.balance  = true;
    }
    else{
        p.balance = false;
    }

    return p;
}


// build a height balanced tree
node* buildTreeFromArray(int *a, int s , int e){
    if(s > e)
        return null;
    
    int mid  = (s+e)/2;
    node*root =new node(a[mid]);
    root->left = buildTreeFromArray(a, s, mid-1);
    root->right = buildTreeFromArray(a, mid+1, e );

    return root;
}


//  if we are given only pre order and inorder then binary tree will be unique
node *createTreeFromTrav(int *in, int * pre,int s, int e ){
    static int i = 0;
    if(s>e){
        return null;
    }

    node*root = new node(pre[i]);
    int index = -1;

    for(int j =s;j<=e;j++){
        if(in[j] == pre[i]){
            index = j;
            break;
        }
    }
    i++;
    root->left = createTreeFromTrav(in, pre, s, index-1);
    root->right = createTreeFromTrav(in, pre,index+1, e);

    return root;
}


int main()
{

    // node *root = buildTree();
    // print(root);
    // cout << endl;
    // in_print(root);
    // cout << endl;
    // post_print(root);
    // cout << endl;
    // cout << height(root) << endl;
    // int h = height(root);
    // print_all_level(root);
    // bfs(root);
    // cout << endl;
    // bfs_other(root);
    // cout<<count(root)<<endl;
    // cout<<sum(root)<<endl;
    // cout<<diameter(root)<<endl;
    // Pair p = diameter_optimized(root);
    // cout<<p.height<<endl;
    // cout<<p.diameter<<endl;
    // replaceNodeWithSum(root);
    // bfs_other(root);

    // if(isHeightBalance(root).balance)
    //     cout<<"true"<<endl;
    // else{
    //     cout<<"false"<<endl;
    // }


    // int a[]  = {1, 2, 3, 4,5 ,6, 7};
    // int n = 7;
    // node*root = buildTreeFromArray(a, 0, 6);
    // bfs_other(root);


    int in[] = {3,2,8, 4, 1, 6, 7 , 5};
    int pre[] = {1,2,3,4,8, 5,6,7};
    int n = sizeof(in)/sizeof(int);

    node *root =createTreeFromTrav(in, pre, 0, n-1);
    bfs_other(root);

    return 0;
}