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

void insert(node*&head, int data){
    

    node *n = new node(data);
    node*temp = head;

    n->next = head;

    if(temp!= NULL)
    {
        while(temp->next!=head){
            temp = temp->next;
        }
        temp->next = n;
    }
    else
    {
        n->next = n;
    }
    

    head = n;
}

// deletion in ciruclar linked list
node*getnode(node*&head, int data){

    node*temp =head;
    while(temp->next!=head)
    {
        if(temp->data == data)
            return temp;

        temp = temp->next;
    }
    // for last node
    if(temp->data == data){
        return temp;
    }

    return NULL;
}
node*getnode2(node*&head, int data){

    node*temp =head;
    while(temp->next!=head)
    {
        if(temp->data == data)
            return temp;

        temp = temp->next;
    }
    // for last node
    if(temp->data == data){
        return temp;
    }

    return NULL;
}
void deleteNode(node*&head,int data ){

    node *del = getnode(head, data);
    if(del == NULL){
        cout<<"node not present"<<endl;
        return;
    }    
    if(head == del){
        head = head->next;  
    }
    node*temp = head;
    // node prev to node to be
    while (temp->next!=del)
    {
        temp = temp->next;
    }
    temp->next = del->next;
    delete del;
    

}

void print(node*head){
    
    node*temp = head;
    while(temp->next != head){
        cout<<temp->data<<" ->";
        temp = temp->next;
    }
    cout<<temp->data<<" ->";
    cout<<endl;
    return ;
}


int main()
{
    node*head = NULL;
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);
    print(head);
    // deleteNode(head, 3);
    // print(head);
    return 0;
}