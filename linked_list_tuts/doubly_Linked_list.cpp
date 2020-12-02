#include<iostream>

using namespace std;

class node{
    public:
    int data;
    node*prev;
    node*next;
    node(){
        prev = NULL;
        next = NULL;
    }
      
};

class doublyLinkedList{
    private:
        node*head;
        node* tail;
    public:
        doublyLinkedList();
        ~doublyLinkedList();
        
        void insert(int d);
        
        void print();

};
doublyLinkedList:: doublyLinkedList(){
    head = new node;
    tail = new node;
    head->next = tail;
    tail->prev = head;
}

void doublyLinkedList:: insert(int d){
    if(head == NULL){
        head ->data = d;
    }

}





int main(){

    return 0;
}