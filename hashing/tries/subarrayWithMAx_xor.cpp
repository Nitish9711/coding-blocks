#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define null NULL

class node{
    public:
    node *left;
    node *right;
  
};

class trie{
    node *root;
    public:
        trie(){
            root = new node();
        }
        void insert(int n){
            node *temp = root;
            for(int i =31;i>=0;i--){
                int bit = (n>>i) & 1;
                if(bit == 0){
                    if(temp->left == null){
                        temp ->left = new node();
                    }
                    temp = temp->left;
                }
                else{  
                    if(temp->right == null){
                        temp ->right = new node();
                    }
                    temp = temp->right;
                }
            }

        }

        int max_xor_helper(int value){
            node *temp = root;
            int current_ans = 0;
            for(int j = 31;j>=0;j--){
                int bit = (value >> j)& 1;
                if(bit == 0){
                    if(temp->right != null){
                        temp = temp->right;
                        current_ans += 1<<j;
                    }
                    else{
                        temp = temp->left;
                    }
                }
                else{
                    if(temp->left != null){
                        temp = temp->left;
                        current_ans += (1<<j);
                    }
                    else{
                        temp = temp->right;
                    }
                }
            }
            return current_ans;
        }

        int max_xor(int *input, int n){
            int max_xor = 0;
            for(int i =0;i<n;i++){
                int val = input[i];
                insert(val);
                int current_xor = max_xor_helper(val);
                // cout<<current_xor<<" ";
                max_xor = max(current_xor, max_xor);
            }
            return max_xor;
        }



};

int main()
{
    trie t;
    int ar[] = {4, 6}; 

    int n = sizeof(ar)/sizeof(ar[0]);
    int input[n];
    input[0] = ar[0];
    for(int i =1;i<n;i++){
        input[i] = ar[i] ^ input[i-1];
    }
    cout<<t.max_xor(input, n)<<endl;
    return 0;
}