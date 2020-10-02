#include<iostream>

using namespace std;
#define ll long int

class node{
    public:
    int data;
    node*next;

    node(int d){
        data = d;
        next =NULL;
    }
};
void print(node*head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}

ll length(node *head){
    ll i = 0;
    while(head != NULL){
        i++;
        head = head->next; 
    }
    return i;
}

void push_back(node*&head, int d){
    if(head == NULL){
        head = new node(d);
        return;
    }

    node*temp =  head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new node(d);
}


node* insert(node* head, node* temp){
    if(head == NULL ||head->data >= temp->data){
       temp->next = head;
       return temp;
    }
    node* parse = head;
    while(head->next != NULL && head->next->data < temp->data){
        head = head->next;
    }
    temp->next = head->next;
    head->next = temp;
    return parse;
    

}


void insertion(node*&head){
    node * result = NULL;
    while(head!= NULL){
        node*temp = head->next;
        result = insert(result, head);
        head = temp;
    }
    head = result;
}


int main(){
    node*head = NULL;
    int n;
    cin>>n;
    int d;
    for(int i=0;i<n;i++){
        cin>>d;
        push_back(head, d);
    }
    insertion(head);
    print(head);

    return 0;
}