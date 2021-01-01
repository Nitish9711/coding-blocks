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

        node *root = new node(d);
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

class HBPair{
    public:
    int height;
    bool balance;
};

HBPair isBalanced(node *root){
    HBPair  p;
    if(root == null){
        p.height = 0;
        p.balance = true;
        return p;
    }

    HBPair left = isBalanced(root->left);
    HBPair right = isBalanced(root->right);

    p.height = max(left.height , right.height) + 1;

    if(abs(left.height - right.height) <=1 && left.balance && right.balance){
        p.balance = true;
    }
    else{
        p.balance = false;
    }
    return p;


}
int main()
{
    node *root = buildTree("true");
    // bfs(root);
    
    if(isBalanced(root).balance){
        cout<<"true";
    }
    else
    {
        cout<<"false";
    }
    
    return 0;
}