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

node *insertInBST(node *root, int d){

    if(root == null)
        return new node(d);
    
    if(d <= root->data){
        root->left = insertInBST(root->left, d);
    }
    else{
        root->right = insertInBST(root->right, d);
    }

    return root;
}


node *buildBST(){
    int d;
    cin>>d;

    node *root = null;
    while(d!=-1){
        root = insertInBST(root, d);
        cin>>d;
    }
    return root;
}

void bfs(node *root){
    queue<node*>q;
    q.push(root);
    q.push(null);

    while (!q.empty())
    {
        node *f = q.front();
        if(f == null){
            cout<<endl;
            q.pop();
            if(!q.empty())
                q.push(null);
        }
        else{
            cout<<f->data<<" ";
            q.pop();
            if(f->left){
                q.push(f->left);
            }
            if(f->right){
                q.push(f->right);
            }
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

bool search(node *root, int d){
    if(root == null)
        return false;

    if(root->data == d)
        return true;
    if(root->data<=d){
        return search(root->left, d);
    }
    else{
        return search(root->right, d);
    }

}

// deletion in BST
node *deleteBST(node *root, int d){
    if(root==null)
        return null;

    else if(d <root->data){
        root->left = deleteBST(root->left, d);
    }
    else if(d== root->data){
        if(root->left== null && root->right == null){
            delete root;
            return null;
        }

        if(root->left!=null && root->right == null){
            node *temp = root->left;
            delete root;
            return temp;
        }
        if(root->left == null && root->right != null){
            node *temp  = root->right;
            delete root;
            return temp;
        }

        node *replace = root->right;
        while (replace->left!= null)
        {
            replace = replace->left;
        }
        root->data = replace->data;
        root->right = deleteBST(root->right, replace->data);
        return root;
    }
    else{
        root->right = deleteBST(root->right, d);
        return root;
    }
}

bool checkBST(node *root , int minV = INT_MIN, int maxV = INT_MAX){
    if(root==null)
        return true;
    
    if(root->data >= minV && root->data <=maxV && checkBST(root->left , minV, root->data) && checkBST(root->right , root->data, maxV))
        return true;

    return false;

}
// convert a tree into linked list
class LinkedList{
    public:
        node*head;
        node*tail;
};

LinkedList flatten(node *root){
    LinkedList l;
    if(root== null){
        l.head =l.tail == null;
        return l;
    }

    if(root->left == null && root->right == null){
        l.head = l.tail = root;
        return l;
    }

    if(root->left != null && root->right == null){
        LinkedList leftLL= flatten(root->left);
        leftLL.tail->right  = root;
        l.head = leftLL.head;
        l.tail = root;
        return l;
    }
    if(root->right != null && root->left == null){
        LinkedList rightLL = flatten(root->right);

        root->right = rightLL.head;
        l.head = root;
        l.tail = rightLL.tail;
    }

    LinkedList leftLL = flatten(root->left);
    LinkedList rightLL = flatten(root->right);

    leftLL.tail->right = root;
    root->right rightLL.head;

    l.head = leftLL.head;
    l.tail = rightLL.tail;
    return l;
}


node *buildTreeFromArray(int *ar , int s , int e){
    if( s > e){
        return null;
    }

     if (s > e)
        return null;

    int mid = (s + e) / 2;
    node *root = new node(a[mid]);
    root->left = buildTreeFromArray(a, s, mid - 1);
    root->right = buildTreeFromArray(a, mid + 1, e);

    return root;

}

node *createTreeFromTrav(int *in, int * pre, int s, int e){
    static int i =0;

    if(s > e){
        return null;
    }

    node *root = pre[i];
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

    root->left = createTreeFromTrav(in, pre, s, index - 1);
root->right = createTreeFromTrav(in, pre, index + 1, e);

return root; 
}


node *util(int pre[], int& preIndex, int key, int min, int max, int size){
    if(preIndex >= size){
        return null;
    }
    if(key > min && key < max){


    }

    
}
node *optimized_build(int *pre,  int n){
  int index = 0;
  return util(pre, index, pre[0], INT_MIN, INT_MAX, n);
}
int main()
{
    // node *root = buildBST();
    // bfs(root);
    // inorder(root);

    // if(checkBST(root)){
    //     cout<<"yes"<<endl;
    // }
    // else{
    //     cout<<"no"<<endl;
    // }

    int pre[] = {5, 3, 1, 7 , 6, 8};
    int n = sizeof(pre)/sizeof(int);
    // int in[n];
    
    
    // for(int i=0;i<n;i++)
    // {
    //     in[i] = pre[i];
    // }
    // sort(in, in+n);
    // node *root =buildFromTrav(in, pre, 0 ,n-1);

    node *root =optimized_build(pre,n);
    bfs(root);
    inorder(root);
    return 0;
}