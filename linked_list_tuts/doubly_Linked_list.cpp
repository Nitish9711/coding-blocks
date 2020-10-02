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
    node(int d){
        data = d;
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
        
        void insertAtHead();
        void insertAtback();
        void insert
        void print();

};
doublyLinkedList:: doublyLinkedList(){
    head = new node;
    tail = new node;
    head->next = tail;
    tail->prev = head;
}

doublyLinkedList:: ~doublyLinkedList(){

}
doublyLinkedList::insertAtHead(){

}


int main(){

    return 0;
}