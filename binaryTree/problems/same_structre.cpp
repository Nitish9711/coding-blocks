#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define null NULL

int x = 0;

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

void print(node *root)
{
    if (root == null)
        return;

    cout << root->data << " ";
    print(root->left);
    print(root->right);
    cout << endl;
}

node *buildTree(string s)
{
    if (s == "true")
    {
        int d;
        cin >> d;
        node *root = new node(d);
        string l;
        cin >> l;
        if (l == "true")
        {
            root->left = buildTree(l);
        }
        string r;
        cin >> r;
        if (r == "true")
        {
            root->right = buildTree(r);
        }

        return root;
    }
    return null;
}


bool check(node *root1, node *root2){
    if(root1 == null && root2 == null)
        return true;
    
    if(root1!=NULL&&root2!=NULL){  
        bool lt=check(root1->left,root2->left);
        bool rt=check(root1->right,root2->right);
        return (lt && rt);        
    }
    return false;
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

int main()
{

    node *root = buildTree("true");
    node *root2 = buildTree("true");

    bfs_other(root);
    bfs_other(root2);
    if(check(root, root2)){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }

    return 0;

}