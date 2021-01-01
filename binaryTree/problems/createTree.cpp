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

node *buildTree(string s){
    if(s == "true"){
        int d;
        cin>>d;
        node *root =new node(d);
        string l;
        cin>>l;
        if(l == "true"){
            root->left = buildTree(l);
        }
        string r;
        cin>>r;
        if(r == "true"){
            root->right = buildTree(r);
        }
        return root;
    }

    return null;
}

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

node *buildTreeFromTrav(int *pre, int *in, int s, int e){

    static int i = 0;
    if(s>e){
        return null;
    }

    int mid = (s+e)/2;
    node *root = new node(pre[i]);
    int index = -1;
    for(int j = s;j<=e;j++){
        if(pre[i] == in[j]){
            index = j;
            break;
        }
    }
    ++i;
    root->left = buildTreeFromTrav(pre, in, s,index-1);
    root->right = buildTreeFromTrav(pre, in, index+1, e);

    return root;
}

void preOrder(node *root){
    
    if(root == null){
        return;
    }
    if(root->left == null){
        cout<<"END => ";
    }
    else
        cout<<root->left->data<<" => ";
    
    cout<<root->data; 

    if(root->right==NULL)
        cout<<" <= END"<<endl;
    else
        cout<<" <= "<<root->right->data<<endl;

    preOrder(root->left);
    preOrder(root->right);
}
int main()
{
    
    node *root = null;
    int n;
    cin>>n;
    int *pre = new int[n];
    for(int i=0;i<n;i++){
        cin>>pre[i];
    }
    int m;
    cin>>m;
    int *in = new int[m];
      for(int i=0;i<m;i++){
        cin>>in[i];
    }

    root = buildTreeFromTrav(pre, in, 0, m-1);
    preOrder(root);

    return 0;
}