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

class linked_list{

    private:
        node*head, *tail;
    
    public:
        linked_list(){
            head =NULL;
            tail = NULL;
        }

        void insertAtTail(int d){

            if(head == NULL){
                head = new node(d);
                tail = head;
            }
            else{
                tail->next = new node(d);
                tail = tail->next;

            }
        }

        void RemoveHead(){
            if(head!= NULL)
                head = head->next;
        }
        void front(){
            cout<<head->data<<endl;
        }
        void print(){
            node *temp = head;
            while(temp!= NULL){
                cout<<temp->data<<"->";
                temp = temp->next;
            }
            cout<<endl;
            
        }

};

class Queue{
    linked_list l;
    int f, r, cs,ms;

    public:
        Queue(){
        }

        void push(int d){
            l.insertAtTail(d);
        }

        void pop(){
            l.RemoveHead();
        }
        void front(){
            l.front();
        }

        void print(){
            l.print();
        }


};

int main(){

    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.pop();
    q.print();
    q.front();

    
    return 0;
}