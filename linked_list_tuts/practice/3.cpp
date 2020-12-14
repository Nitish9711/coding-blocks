#include <iostream>
using namespace std;
#define null NULL

class node{
    public:
    int data;
    node *next;
    node *prev;
    node(int d){
        data = d;
        next = NULL;
        prev = NULL;
    }
};


void print(node *head){
    
    while(head!= NULL){
        cout<<head->data<<"->";
        head = head->next;
    }

}

void insertAtHead(node *&head, int data){

    if(head == null){
        head = new node(data);
        return;
    }
    node *temp = head;
    node *n = new node(data);
    n->next = head;
    head->prev = n;

    head = n;
}

void insertAtEnd(node *&head, int data){
    if(head == NULL){
        head  = new node(data);
        return;
    }

    node *temp = head;
    while(temp->next!= null){
        temp = temp->next;
    }
    node *n = new node(data);
    temp->next = n;
    n->prev = temp;
}
int length(node*head){
    int count = 0;
    while(head!=NULL){
        count++;
        head = head->next;
    }
    return count;

}

void insertAtMiddle(node *&head, int data, int p){

    if(p == 0){
        insertAtHead(head, data);
    }
    else if( p > length(head)){
        insertAtEnd(head, data);
    }


}

 

int main()
{
    node *head = NULL;
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    insertAtEnd(head, 4);
    print(head);
    return 0;
}