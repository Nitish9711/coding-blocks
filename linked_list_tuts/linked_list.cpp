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


// operator overloading

ostream& operator<<(ostream &os, node* head){
    print(head);
    return os;
}

istream& operator>>(istream & is, node*&head){
    head = take_input_2();
    return is;
}

// reversing linked list

void reverse(node *&head){
    node *  C = head;
    node * P = NULL;
    node *N;

    while (C!=NULL)
    {
        // SAVING THE NEXT NODE
        N = C->next;
        
        // MAKE THE CURRENT NODE POINT TO PREVIOUS
        C->next = P;
        // UPDATING P AND C take the 1 step forward
        P = C;
        C = N;
        
    }
    head = P;
     
}

// recursively reserve a linked list
// optimized
node* recReverse(node*head){
    // smallest linked list base case
    if(head->next == NULL or head == NULL)
        return head;
    
    // rec case
    node * shead = recReverse(head->next); 
    head->next->next =head;
    head->next = NULL;
    return shead;
}

// node* recReverse(node*head){
//     // smallest linked list base case
//     if(head->next == NULL or head == NULL)
//         return head;
    
//     // rec case
//     node * shead = recReverse(head->next);
//     node *temp = shead;

//     while(temp->next!= NULL){
//         temp = temp->next;
//     }

//     head->next = NULL;
//     temp->next =head;
//     return shead;
// }


// midpoint of a linked list
// runner tehnique
node*midpoint(node*head){
    if(head == NULL or head->next == NULL)
        return head;

    node*slow = head;
    node*fast = head->next;

    while(fast!=NULL and fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}


// k-th node form end
node* k_th_node(node*head, int k){
    if(head == NULL or head->next== NULL)
        return head;

    node*slow = head;
    node*fast = head;   

    int i =0;
    while(i<k){
        if(fast == NULL){
            std::cout<<"out of range"<<endl;
            return NULL;
        }
        fast =fast->next;
        i++;
    }

    while(fast!=NULL){
        fast= fast->next;
        slow = slow->next;
    }

    return slow;   
    
}

// merging two sorted linked list
node*merge(node*a, node*b){
    if(a == NULL)
        return b;
    if(b==NULL)
        return a;

    node*c ;
    if(a->data < b->data){
        c = a;
        c->next = merge(a->next, b);
    }
    else{
        c = b;
        c->next= merge(a, b->next);
    }
    return c;

}

// mege_sort
node* mergeSort(node*head){
    if(head == NULL or head->next == NULL)
        return head;
    
    // rec case
    node*mid = midpoint (head);
    node*a = head;
    node*b = mid->next;

    // breaking the linked list about mid point
    mid->next = NULL;

    // recursively sort
    a = mergeSort(a);
    b = mergeSort(b);

      
    // merge a, b
    node *c = merge(a, b);
    return c;
}


// floyd's cycle
// cycle detection and removal
// 
void RemoveCycle (node*slow, node*fast){
   
    // node* slow = head;

    while (slow->next != fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }
    fast->next = NULL;
    
     
}
bool detectCycle (node*head){
    if (head == NULL || head->next == NULL) 
        return false; 
    node*slow = head;
    node*fast = head;
    
    while(fast!=NULL && fast->next!= NULL)
    {
        slow = slow->next;
        fast= fast->next->next;
        
        if(fast == slow){
            RemoveCycle(head, fast);
            return true;
        }
    }
    return false;   
}

int main()
{
    // node*head = take_input_2();
    // node*head2 = take_input_2();
    node* head;
    node* head2;
    // cout<<head;
    // cout<<head2;

    // by cascading operator
    // cin>>head>>head2;
    // cout<<head<<head2;
    cin>>head;
    // cin>>head2;
    cout<<head;


    // cout<<head2;
    // head  = recReverse(head);
    // cout<<head;


    // midpoint;
    // node*mid = midpoint(head);
    // cout<<mid->data<<endl;
    
    // k-th from end
    // node* k_node = k_th_node(head, 3);
    // cout<<k_node->data<<endl;

    // merging linked list
    // node* merged_linked_list = merge(head, head2);
    // cout<<merged_linked_list;

    // merge_sort
    // head = mergeSort(head);
    // cout<<head<<endl;

    // detect and remove
    //  creating a cycle
    head->next->next->next->next->next = head->next->next; 
    if(detectCycle(head))
        cout<<"yes cycle found and disconnected"<<endl;
    else
    {
        cout<<"cycle not found"<<endl;
    }
    if(detectCycle(head))
        cout<<"yes cycle found and disconnected"<<endl;
    else
    {
        cout<<"cycle not found"<<endl;
    }
    

     
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