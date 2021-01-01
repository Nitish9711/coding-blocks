#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define null NULL

class node{
    public:
    int data;
    node *left;
    node*right;
    node(int d){
        data =d;
        left = null;
        right = null;

    }
};



void bfs(node *root){

    if(root == null){
        return;
    }
    queue<node *>q;
    q.push(root);
    q.push(null);
    while (!q.empty())
    {
        node *f = q.front();
        if(f == null){
            cout<<endl;
            q.pop();
            if(!q.empty()){
                q.push(null);
            }
        }
        else{
            cout<<f->data<<" ";
            q.pop();
            if(f->left)
                q.push(f->left);
            if(f->right)
                q.push(f->right);
        }
    }
    
}

node *buildFromTrav(int *pre , int *in, int s, int e){

    static int i =0;
    if(s > e){
        return null;
    }

    node *root = new node(pre[i]);
    int index = -1;
    for(int j = s;j<=e;j++){
        if(in[j] == pre[i]){
            index = j;
            break;
        }
    }

    ++i;
    root->left = buildFromTrav(pre, in, s, index-1);
    root->right = buildFromTrav(pre, in, index + 1, e);

    return root;
}

bool isBST(node *root, int minVal = INT_MIN, int maxVal = INT_MAX){
    if(root == null)
        return true;
    
    if(root->data >= minVal  && root->data <= maxVal && isBST(root->left, minVal, root->data) && isBST(root->right, root->data, maxVal)){
        return true;
    }   
    return false;
}

int size(node *root){
    if(root == null)
        return 0;
    
    return size(root->left) + 1 + size(root->right);
}



int largestBST(node *root){
    if(isBST(root)){
        return size(root);
    }

    return max(largestBST(root->left), largestBST(root->right));
}

int main()
{
    
    int n;
    cin>>n;
    int *pre = new int[n];
    int *in  = new int[n];
    for(int i=0;i<n;i++){
        cin>>pre[i];
    }
    for(int i=0;i<n;i++){
        cin>>in[i];
    }
    node *root = buildFromTrav(pre, in, 0, n-1);
    // bfs(root);

    cout<<largestBST(root)<<endl;

    return 0;
}