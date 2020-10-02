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


void print(node * head){

    while(head!= NULL){
        cout<<head->data<<" ->";
        head = head->next;
    }
    cout<<endl;
}

int length(node*head){
    int len  = 0;
    while(head!= NULL)
    {
        head = head->next;
        len++;
    }
    return len;
}

void insertAtHead(node*&head, int d){

    if(head == NULL){
        head = new node(d);
        return;
    }

    node*n = new node(d);
    n->next = head;
    head = n;
    return;
}

void insertAtTail(node*&head, int d){
    node * new_node = new node(d);
    if(head == NULL){
        head = new_node;
        return;
    }

    node* tail = head;
    
    while(tail->next != NULL){
        tail = tail->next;
    }
    tail->next = new_node; 
}

void insertAtMiddle(node*&head, int d, int p){

    if(head == NULL or p == 0){
        insertAtHead(head, d);
    }
    if(p>length(head))
    {   
        insertAtTail(head, d);
        return;
    }

    node* new_node =new node(d);
    int jump = 1;
    node*temp = head;
    while(jump<=p-1){
        temp = temp->next;
        jump++;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}

void deleteAtHead(node*&head){
    
    if(head == NULL){
        return;
    }
    node*temp = head->next;
    delete head;
    head = temp;

}
void deleteAtTail(node*&head){
    node*secondLast = head;
    while(secondLast->next->next != NULL){
        secondLast = secondLast->next;
    }
    delete secondLast->next;
    secondLast->next = NULL;
}

void deleteAtMiddle(node*head, int p){

    if(p == 0 or head == NULL){
        deleteAtHead(head);
        return;
    }
    else if(p == length(head)){
        deleteAtTail(head);
    }
    else
    {
        node*temp = head;
        int i=1;
        while(i<p){
            temp = temp->next;
            i++;
        }
        temp->next = temp->next->next;
    }
}

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

node*take_input(){
    int d ;
    cin>>d;
    node*head = NULL;
    while(d!=-1){
        insertAtHead(head, d);
        cin>>d;
    }

    return head;
}

node*take_input_file(){
    int d;
    node*head = NULL;
    // read input till end of file is recognised
    while (cin>>d)
    {
        insertAtHead(head, d);
    }
    return head;
    
}

// operator overloading
ostream& operator<<(ostream& os, node*&head){
    print(head);
    return os;
}

istream& operator>> (istream& is, node*&head){
    head = take_input();
    return is;
}

// reverse a linked list
void reverse(node*&head){
    node * C = head;
    node* P = NULL;
    node * N;
    while(C!= NULL){
        N= C->next;
        C->next = P;
        P = C; 
        C= N; 
    }
    head = P;
}

node* recReverse(node*head){
    // smallest linked list base case
    if(head->next == NULL or head == NULL)
        return head;
    
    // rec case
    node * shead = recReverse(head->next);
    node *temp = shead;

    while(temp->next!= NULL){
        temp = temp->next;
    }

    head->next = NULL;
    temp->next =head;
    return shead;
}

// optimized reverse
node* optimized(node*head){
    if(head->next == NULL or head == NULL)
        return head;
    
    node*shead= optimized(head->next);
    head->next->next= head;
    head->next= NULL;
    return shead;

}



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

node* k_th_node(node*head, int k){
    if(head == NULL || head->next == NULL){
        return head;
    }

    node*slow = head;
    node*fast = head;
    int i =0;
    while(i<k){
        if(fast== NULL)
        {
            cout<<"out of range"<<endl;
            return NULL;
        }
        fast = fast->next->next;
        i++;
    }
    while(fast!= NULL){
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}

node* merge(node* a, node*b){
    if(a== NULL)
        return b;
    if(b == NULL)
        return a;
    
    node * c;
    if(a->data > b->data)
    {
        c = a;
        c->next = merge(a->next, b);
    }
    else{
        c = b;
        c->next= merge(a, b->next);
    }
    return c;
}


node* merge_sort(node*head){

    if(head == NULL or head->next == NULL)
        return head;
    
    node*mid = midpoint(head);
    node*a  = head;
    node* b = mid->next;
    mid->next = NULL;
    a = merge_sort(a);
    b = merge_sort(b);

   node *c = merge(a, b);
   return c;
}
int main()
{
    // freopen("input.txt", "r", stdin);
    // node *head = take_input_file();
    node*head;
    cin>>head;
    cout<<head<<endl;
    
    cout<<head->next->next->data;
   
  

    return 0;
}