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
    cout<<endl;
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
       cout<<"temp ";
       print(temp);
       return temp;
    }
    node* parse = head;
    cout<<"parse init ";
    print(parse);
    while(head->next != NULL && head->next->data < temp->data){
        head = head->next;
    }
    temp->next = head->next;
    head->next = temp;
    cout<<"parse ";
    print(parse);
    return parse;    
}

void insertion(node*&head){
    node * result = NULL;
    while(head!= NULL){
        node*temp = head->next;
        cout<<"head ";
        print(head);
        cout<<"temp insertion ";
        print(temp);
        cout<<"result in ";
        print(result);
        result = insert(result, head);
        head = temp;
        cout<<"head out";
        print(head);
        cout<<"result out ";
        print(result);
    }
    head = result;
}
int main(){
    node*head = NULL;
    push_back(head, 3);
    push_back(head, 2);
    push_back(head, 4);    
    insertion(head);
    print(head);
    cout<<head->next->data<<endl;

    cout<<&head<<" "<<head<<" "<<" "<<head->data<<" "<<&(head->data)<<endl;
    cout<<&head->next<<" "<<head->next<<" "<<head->next->data<<" "<<&(head->next->data)<<endl;
    cout<<&head->next->next<<" "<<head->next->next<<" "<<head->next->next->data<<" "<<&(head->next->next->data)<<endl;
    cout<<&head->next->next->next<<" "<<head->next->next->next<<" "<<head->next->next->next->data<<" "<<&(head->next->next->next->data)<<endl;
    
    
    print(head);

    return 0;
}