#include<iostream>

using namespace std;

class node{
  public:
    int data;
    node*next;

    node(int d){
        data  = d;
        next = NULL;
    }     
};

// LINKED CLASS (OBJECT ORIENTED)
/*class LinkedList
{
    node* head;
    node*tail;
public:
    LinkedList(){

    }
    void insert(int d){

    }

   
};*/



// FUNTION (PROCEDURAL PROGRAMMING)
void build(){

}
void insertAtHead(node*&head, int d){
    if(head == NULL){
        head = new node(d);
        return;
    }

    node *n = new node(d);

    // (*n).next = head;
    n->next = head;
    head = n;

}

void insertAtTail(node*&head , int data)
{
    if(head == NULL){
        head = new node(data);
        return;
    }
    node*tail = head;
    while (tail->next !=NULL)
    {
       tail = tail->next;
    }
    tail->next = new node(data);
    return; 

}


void print(node*head){
    while(head!=NULL){
        cout<<head->data<<" ->";
        head = head-> next;
    }
    cout<<endl;
}

int length (node* head){
    int cnt = 0;
    while(head!= NULL){
        cnt++;
        head = head->next;
    }
    return cnt;
}

void insertInMiddle(node*& head, int data, int p ){
    // corner case
    if(head == NULL or p== 0){
        insertAtHead(head, data);
        return;
    }

    else if(p > length(head)){
        insertAtTail(head, data);
    }
    else
    {
        int jump =1;
        node*temp = head;
        while (jump<=p-1)
        {
            temp = temp->next;
            jump++;
        }
        // create a new node
        node *n = new node(data);
        n->next = temp->next;
        temp->next = n;
        
    }
    
}

void deletAtHead(node*&head){
    if(head == NULL)
        return;
    
    node* temp = head->next;
    delete head;
    head = temp;
}


void deleteAtTail(node*&head){
        node* SecondLast = head;
        while(SecondLast->next->next !=NULL)
        {
            SecondLast = SecondLast->next;
        }
        delete SecondLast->next;
        SecondLast->next = NULL;
        
}


void deleteAtMiddle(node*&head, int pos){
    if(head == NULL or pos== 0){
        deletAtHead(head);
        return;
    }
    else if(pos == length(head)){
       
        deleteAtTail(head);
    }
    else{
        cout<<"deleteing in middele "<<endl;
        node * temp = head;
        for (int i=0; temp!=NULL && i<pos-1; i++) 
        {
            temp = temp->next; 
        }
        // cout<<"data "<<temp->data<<endl;
        if (temp == NULL || temp->next == NULL) 
         return; 
        
        node * n =temp->next;
        // cout<<n->data<<endl;
        
        temp->next = n->next;
        delete n;
        
    }
       
}

// searching
// linear search

bool search(node*head, int key){
    node* temp = head;
           
    while(temp!=NULL)
    {
        if(temp->data == key){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

// recursive approach

bool searchRecursive(node * head, int key){
    
    if(head == NULL)
        return false;
    if(head->data == key)
        return true;
    else{

        return searchRecursive(head->next, key);
    }
    
}

// taking input

void take_input(node*&head){

}

node* take_input_2()
{
    int d;
    cin>>d;
    node * head = NULL;
    while ((d!=-1))
    {
        insertAtHead(head, d);
        cin>>d;
    }
    return head;
    
}
node* take_input_from_file()
{
    int d;
   
    node * head = NULL;
    while (cin>>d)
    {
        insertAtHead(head, d);
    }
    return head;
    
}

int main()
{
    freopen("input.txt","r",stdin);
    node*head = take_input_from_file();

    print(head);
    // node*head = NULL;
    // // print(head);
    // insertAtHead(head, 5);
    // insertAtHead(head, 2);
    // insertAtHead(head, 1);
    // insertAtHead(head, 0);
    
    // print(head);
    // insertInMiddle(head, 4, 3);
    // insertAtTail(head, 7);
    // print(head);
    // deletAtHead(head);
    // print(head);
    // // deleteAtTail(head);
    // print(head);
    // // insertAtTail(head, 7);
    // deleteAtMiddle(head, 2);
    // print(head);
    // int key;
    // cin>>key;
    // if(search(head, key))
    // {
    //     cout<<"found"<<endl;
    // }
    // else
    //     cout<<" not found"<<endl;


    return 0;
}