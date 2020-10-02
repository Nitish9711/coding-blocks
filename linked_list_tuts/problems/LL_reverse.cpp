#include<iostream>

using namespace std;

class node{
    public:
    int data;
    node*next;
    node(int d){
        data = d;
        next = NULL;
    }
};

void insertAtEnd(node*&head, int data){

   
    if(head == NULL){
        head = new node(data);
        return;
    }

    node* temp = head;
    while(temp->next!= NULL){
        temp = temp->next;
    }
    temp ->next = new node(data);

    return;

}

node* reverse(node*&head, int k){
    
    node*C = head;
    node*N = NULL;
    node*P = NULL;
    int cnt = 0;

    while(C!= NULL && cnt<k){
        N = C->next;
        C->next = P;
        P = C;
        C = N;
        cnt++;
    }

    if(N!= NULL)
    {
        head->next = reverse(N, k);
    }
    
    return P;

    
}


void print(node*head){
    
    while(head!= NULL){
        cout<<head->data<<" ";
        head = head->next;
        
    }
    // cout<<endl;

    return;
}

int main(){
    node*head = NULL;
    int n,k;
    cin>>n>>k;

    for(int i=0;i<n;i++)
    {
        int d;
        cin>>d;
        insertAtEnd(head, d);
    }
    // print(head);
    head = reverse(head, k);
    print(head);
    return 0;
}