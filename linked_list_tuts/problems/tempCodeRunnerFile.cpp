#include<iostream>

using namespace std;
#define ll long int

class node{
    public:
    int data;
    node*next;

    node(int d){
        data = d;
        next =NULL;
    }
};
void print(node*head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}

ll length(node *head){
    ll i = 0;
    while(head != NULL){
        i++;
        head = head->next; 
    }
    return i;
}

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


node* reverse(node * head){
    if(head == NULL ||head->next == NULL)
        return head;

    node*shead = reverse(head->next);
    head ->next->next  = head;
    head->next = NULL;
    return shead;
}

bool check(node*head){
    ll len = length(head);
    node*temp  = head;
    int mid = len/2;
    while(mid){
        temp = temp->next;
        mid--;
    }
    // cout<<temp->data<<endl;
    node*rev= NULL;
    if(len%2 == 0)
       rev = reverse(temp);
    else
       rev = reverse(temp);

    // print(rev);
    // cout<<endl;
    mid = len/2;
    while(mid){
        if(rev->data != head->data ){
            return false;
        }
        rev = rev->next;
        head = head->next;
        mid--;
    }
    // cout<<rev->data<<endl;;
    return true;

    

}


int main(){
    node*head = NULL;
    int n;
    cin>>n;
    int d;
    for(int i=0;i<n;i++){
        cin>>d;
        push_back(head, d);
    }
    if(check(head)){
        cout<<"true";
    }
    else
    {
        cout<<"false";
    }
    
    // print(head);

    return 0;
}