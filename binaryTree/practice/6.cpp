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

node *insertInBST(node *root, int d)
{

    if (root == null)
        return new node(d);

    if (d < root->data)
    {
        root->left = insertInBST(root->left, d);
    }
    else
    {
        root->right = insertInBST(root->right, d);
    }

    return root;
}

void preOrder(node *root)
{
    if (root == null)
        return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
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

node* buildBST(int a[], int start, int end){
	//Base
	if(start>end){
		return NULL;
	}
	int middle= start + (end-start)/2;
	node* root= new node(a[middle]);

	root->left= buildBST(a, start, middle-1);
	root->right= buildBST(a, middle+1, end);

	return root;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int *ar = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> ar[i];
            // bfs_other(root);
        }
        node *root = buildBST(ar, 0, n - 1);
        preOrder(root);
        cout << endl;
    }
    return 0;
}