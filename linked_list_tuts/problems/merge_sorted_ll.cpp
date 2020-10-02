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

node* merge(node * a, node * b){
    if(a == NULL)
        return b;
    if(b == NULL)
        return a;
    node *c;

    if(a->data < b->data)
    {
        c = a;
        c->next = merge(a->next, b);
    }
    else
    {
        c = b;
        c->next = merge(a, b->next);
    }a

    return c;
}






void print(node*head){
    
    while(head!= NULL){
        cout<<head->data<<" ";
        head = head->next;
          }
    return;
}

int main(){

    int t;
    cin>>t;

    while(t--){
        int n1, n2;
        cin>>n1;
        node*head1 = NULL;
        for(int i =0;i<n1;i++)
        {   int d;
            cin>>d;
            insertAtEnd(head1, d);
        }
        node * head2 = NULL;
        cin>>n2;
        for(int i=0;i<n2;i++)
        {
            int d;
            cin>>d;
            insertAtEnd(head2, d);
        }
        node *c = merge(head1, head2);
        print(c);
		cout << endl;
    }
    return 0;
}