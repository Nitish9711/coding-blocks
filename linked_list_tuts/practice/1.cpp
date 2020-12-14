#include <iostream>
#include <bits/stdc++.h> 
using namespace std;
#define null NULL

class node{
    public:
    int data;
    node *next;
    node(int d){
        data = d;
        next = NULL;
    }
};



void print(node *head){

    while (head!=NULL)
    {
        cout<<head->data<<" ->";
        head = head->next;    
    }

    cout<<endl;
    
}


void insertAtHead(node*&head, int d){
    if(head == NULL){
        head = new node(d);
        return;
    }

    
    node *n = new node(d);
    n->next = head;
    head= n;

}

void insertAtEnd(node*&head, int data){

    if(head ==NULL){
        head = new node(data);
        return;
    }

    node*tail = head;

    while(tail->next!=NULL){
        tail= tail->next;
    }
    tail->next = new node(data);

    return;

}

int length(node*head){
    int count = 0;
    while(head!=NULL){
        count++;
        head = head->next;
    }
    return count;

}

void insertInMiddle(node*&head, int d, int p){

    if(head == NULL or p ==0){
        insertAtHead(head, d);
        return;
    }
    else if(p > length(head)){
        insertAtEnd(head, d);
    }
    else{

        int jump = 1;
        node*temp = head;
        while(jump <=p-1){

            temp= temp->next;
            jump++;
        }

        node *n = new node(d);
        n->next = temp->next;
        temp->next = n;
    }



}

void deleteHead(node*&head){
    if(head ==NULL){
        return;
    }
    node*temp = head->next;
    delete head;
    head = temp;
}
void deleteTail(node *&head){
    if(head==NULL){
        return;
    }

    node *temp = head;

    while(temp->next->next!=NULL){
        temp = temp->next;
    }
    node *prev = temp;
    delete (temp->next);
    prev->next  = NULL;
     
}
void deleteInMiddle(node *&head, int pos){

    if(head ==NULL ){
        cout<<"linked list is empty";
        return;
    }
    if(pos == 0){
        deleteHead(head);
        return;
    }
    else if(pos == length(head)){
        deleteTail(head);
        return;
    }
    else{
        node *temp = head;
        for(int i = 0;i<pos-1;i++){
            temp = temp->next;
        }
        if(temp == NULL or temp->next == NULL)
            return;

        node  * n = temp->next;
        temp->next = n->next;
        delete n;
        
    }


}

bool search(node *head, int key){
  
    node *temp = head;
    while (temp!=NULL)
    {
        if(temp->data ==key){
            return true;
        }
        temp = temp->next;
    }
    return false;
}


bool recSearch(node *head, int key){
    
    if(head ==NULL){
        return false;
    }

    if(head->data == key){
        return true;
    }

    return recSearch(head->next, key);
}



node* take_input(){
    int d;
    cin>>d;
    node*head = NULL;
    while(d!=-1){
        insertAtEnd(head, d);
        // insertAtHead(head, d);
        cin>>d;
    }
    return head;

}

node *take_input_from_file(){
    fstream file;
    file.open("input.txt");
    int d;

    node*head = NULL;
    while(file>>d){
        insertAtEnd(head, d);
    }
    return head;
}

// cascading of operators
ostream& operator<<(ostream &os, node* head){
    print(head);
    return os;
}

istream& operator>>(istream & is, node*&head){
    head = take_input_from_file();
    return is;
}

void reverse(node *&head){
    node *c = head;
    node*p = NULL;
    node * n;

    while(c!=NULL){
        n = c->next;
        c->next = p;
        p = c;
        c = n;
    }
    head = p;

}

node* optimized_reverse(node*head){
    if(head == NULL or head->next == NULL){
        return head;
    }
    node * shead = optimized_reverse(head->next); 
    node*temp = head->next;
    temp->next = head;
    head->next = NULL;
    return shead;
}

node* recreverse(node*&head){

    if(head->next == NULL or head == NULL)
        return head;
    
    // rec case
    node * shead = recreverse(head->next);
    node *temp = shead;

    while(temp->next!= NULL){
        temp = temp->next;
    }

    head->next = NULL;
    temp->next =head;
    return shead;
}

node *midpoint(node*&head){
    node *slow = head;
    node*fast = head->next;

    while(fast!= NULL and fast->next!= NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

node *k_node(node*&head, int k){
    node *slow = head;
    node*fast = head;
    int i =0;
    while(i<k){
        if(fast == NULL){
            std::cout<<"out of range"<<endl;
        }
        fast = fast->next;
        i++;
    }
    while(fast!=NULL){
        fast = fast->next;
        slow= slow->next;
    }
    return slow;

}

node * merge(node *a, node *b){
    
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
node* merge_sort(node*head){
    if(head == NULL or head->next == NULL)
    return head;

    node *mid = midpoint(head);
    node *a = head;
    node * b = mid->next;
    mid->next = NULL;

    a = merge_sort(a);
    b = merge_sort(b);

    node *c = merge(a, b);
    return c;
} 

void removeCycle(node *slow, node *fast){
    while(slow ->next != fast->next){
        slow = slow->next;
        fast = fast->next;

    }
    fast->next = NULL;
    
}
bool detectCycle(node *head){
    node*fast = head;
    node*slow = head;

    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow){
            removeCycle(slow, fast);
            return true;
        }
    }
    return false;

}
int main()
{  

    node*head = NULL;
    cin>>head;
    cout<<head;
    node *c = merge_sort(head);
    // head = midpoint(head);
    cout<<c;

    // node *head1 = NULL;
    // cin>>head1;
    // cout<<head1;
    // node *head = NULL;
    // cin>>head;
    // cout<<head;
    // head = merge(head1, head);
    // cout<<head;.

    // node*head = NULL;
    // cin>>head;
    // cout<<head;
    // head = k_node(head, 3);
    // // head = midpoint(head);
    // cout<<head->data;


    // reverse 
    // node*head = NULL;
    // cin>>head;
    // cout<<head;
    // head = optimized_reverse(head);
    // cout<<head;


    // // operator overloading
    // node *head = NULL;
    // cin>>head;
    // cout<<head;
  

     // input from file
    // node *head = take_input_from_file();
    // print(head);
    // deleteInMiddle(head, 2);
    // print(head);
    


    // node *head = NULL;
    // insertAtHead(head, 5);
    // insertAtHead(head, 2);
    // insertAtHead(head, 1);
    // insertAtHead(head, 0);
    // print(head);
    // insertInMiddle(head, 3,3);
    // insertInMiddle(head, 4,4);
    // insertAtEnd(head, 6);
    // print(head);    
    // // deleteHead(head);
    // print(head);    
    // // deleteTail(head);
    // print(head);    
    // if(recSearch(head, 2)){
    //     cout<<"Yes"<<endl;
    // }
    // else{
    //     cout<<"No"<<endl;
    // }


    // node *head = take_input();
    // print(head);

   



    return 0;
}