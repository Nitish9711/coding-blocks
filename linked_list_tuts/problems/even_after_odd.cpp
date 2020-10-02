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

void change(node*&head){
   node *odd = NULL;
   node* even = NULL;
   node* temp = head;
   while(temp!= NULL){
       if(temp->data %2 == 0){
           push_back(even, temp->data);
           even = even->next;
       }
       else
        {
            push_back(odd, temp->data);
            odd = odd->next;
        }
        temp = temp->next;
   }

   odd->next = even;
   head = odd;




}


void print(node*head){
    
    while(head!= NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    return;
}




int main(){
    node* head = NULL;
    int n;
    cin>>n;
    int d;
    for(int i=0;i<n;i++)
    {
        cin>>d;
        push_back(head, d);
    }
    change(head);
    print(head);
    return 0;
}