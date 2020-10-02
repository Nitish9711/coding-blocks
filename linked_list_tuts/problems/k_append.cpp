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

void insertAtEnd(node*&head, int data){

   
    if(head == NULL){
        head = new node(data);
        return;
    }

    node* temp = head;
    while(temp->next!= NULL){
        temp = temp->next;
    }
    temp ->next = new node(data);

    return;

}

node* append( node *head, int k){

   node*oldHead = head;
   node*fast = head;
   node*slow = head;
   int i =0;
   while(i<k ){
       fast = fast->next;
    //    cout<<fast->data<<endl;
       i++;
   }
   while (fast!=NULL && fast->next !=NULL)
   {
       fast = fast->next;
       slow = slow->next;
   }
  
    //    cout<<slow->data<<endl;
   node* newHead = slow->next;
   slow->next = NULL;
       fast->next = oldHead;
//    cout<<fast->data<<endl;
   return newHead;


}






void print(node*head){
    
    while(head!= NULL){
        cout<<head->data<<" ";
        head = head->next;
        
    }
    return;
}

int main(){

    int n;
    cin>>n;

    node*head = NULL;
    int d;
    for(int i=0;i<n;i++){
        cin>>d;
        insertAtEnd(head, d);
    }
    int k ;
    cin>>k;
    k= k%n;
    if(k == 0)
        print(head);
    else
    {   
        head = append(head, k);
        print(head);
    }
    
    return 0;
}