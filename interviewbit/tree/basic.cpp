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
// int diameter(node *root){
//     if(root == null)
//         return 0;

//     int h1 = height(root->left);
//     int h2 = height(root->right);

//     int op1 = h1+ h2;
//     int op2 = diameter(root->left);
//     int op3 = diameter(root->right);
//     return max(op1, max(op2, op3));

// }
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
// check tree is height balanced or not
class HBPair{
    public:
    int height;
    int balance;

};
HBPair isHeightBalanced(node *root){
    HBPair p;
    if(root == null){
        p.height =0;
        p.balance = true;
        return p;
    }

    HBPair left, right;
    left = isHeightBalanced(root->left);
    right = isHeightBalanced (root->right);


    p.height = max(left.height , right.height) + 1;
    if(abs(left.height - right.height )<=1 && left.balance && right.balance)
        p.balance= true;
    else
        p.balance = false;
    return p;
}

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
void PrintATLevelK(node *root, int k){
     if (root == null)
    {
        return;
    }

    if (k == 0)
    {
        cout << root->data << " ";
        return;
    }

    PrintATLevelK(root->left, k - 1);
    PrintATLevelK(root->right, k - 1);
    return;
}
int PrintAtDistanceK(node *root, node *target, int k){
    if(root == null)
        return -1;
    
    if(root == target)
    {
        PrintATLevelK(target, k);
        return 0;
    }
    int dl = PrintAtDistanceK(root->left, target, k);
    if(dl != -1){
        if(dl + 1 ==k){
            cout<<root->data<<" ";

        }
        else{
            PrintATLevelK(root, k-2 -dl);
        }
        return dl + 1;
    }
    int dr = PrintAtDistanceK(root->right, target, k);
    if (dr != -1)
    {
        if (dr + 1 == k)
        {
            cout << root->data << " ";
        }
        else
        {
            PrintATLevelK(root->right, k - 2 - dr);
        }
        return dr + 1;
    }
    return -1;

}


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
class Pair
{
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
    if(root == null)
        return p;

    Pair left = maxSumPath(root->left);
    Pair right = maxSumPath (root->right);

    int op1 = root->data;
    int op2 = left.branchSum + root->data;
    int op3 = right.branchSum + root->data;
    int op4 = left.branchSum + right.branchSum + root->data;

    int current_ans = max(op1,max(op2, max(op3, op4)));
    p.branchSum = max(left.branchSum , max(right.branchSum , 0)) + root->data;
    p.maxSum = max(left.maxSum , max(right.maxSum , 0)) + root->data;
    return p;
}

// shortest distance between 2 nodes
// finding the level of given level
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


void diagonal_traversal(node *root){
    
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