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

void k_end(node*head, int k){
   node*slow =head;
   
   node*fast= head;
   while(k > 1){
       fast = fast ->next;
       k--;
   }
  while (fast!=NULL && fast->next !=NULL)
   {
       fast = fast->next;
       slow = slow->next;
   }
    cout<<slow->data<<endl;

   

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
    int d;
    while(1)
    {
        cin>>d;
        if(d== -1)
            break;
        push_back(head, d);
    }
    int k;
    cin>>k;
    k_end(head, k);   
    
    return 0;
}