#include<iostream>

using namespace std;
#define null NULL

class node{
    public:
    int data;
    node*next;
    node(int d){
        data = d;
        next = null;
    }

};

class Linked_list{
    node *head = null;

    public:
        void push(int d);
        void display();
        int peek();
        void pop();
        bool isEmpty();

};
bool Linked_list::isEmpty(){
    if(head!= null){
        return false;
    }
    return true;
}

void Linked_list::display(){
    node *temp = head;
    while(temp !=NULL){
        cout<<temp->data<<" -> ";
        temp = temp->next;
    }
    cout<<endl;
}

int Linked_list::peek(){
    if(isEmpty()){
        cout<<"stack is empty"<<endl;
        return 0;
    }

    return head->data;

}

void Linked_list::push(int x){
    node *n = new node(x);
    n->next = head;
    head = n;
}

void Linked_list::pop(){
    if(isEmpty()){
        cout<<"nothing to pop"<<endl;
        return;
    }

    int d  = head->data;
    head = head->next;
    cout<<d<<" has been poped "<<endl;
}


int main(){
    Linked_list l;
    l.push(1);
    l.push(2);
    l.display();
    // cout<<endl;
    l.push(3);
    l.push(4);
    l.display();

    cout<<l.peek()<<endl;
    // l.display();
    l.pop();
    l.display();
    l.pop();
    l.display();
    return 0;
}