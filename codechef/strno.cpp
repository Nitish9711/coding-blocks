#include<iostream>
using namespace std;
class node{
int data;
public:

   node *next;
   node(int data)
   {
    this->data=data;
    this->next=NULL;

   }
   node*takeinput()
   {
       int data;
       cin>>data;
       node*head=NULL;
       while(data!=-1)
       {
           node*newnode=new node(data);
         if(head==NULL)
         {
             head=newnode;
         }
         else
        {
          node*temp=head;
          while(temp->next!=NULL)
          {
              temp=temp->next;
          }
          temp->next=newnode;
         }
         cin>>data;
       }
       return head;

   }
   void print(node *head)
   {
       node*temp=head;
       while(temp!=NULL)
       {
           cout<<temp->data<<" ";
           temp=temp->next;
       }
       cout<<endl;
       while(head!=NULL)
       {
           cout<<head->data<<" ";
           head=head->next;
       }
   }


};
int main()
{
    node*head=takeinput();
    print(head);
    /*node n1(10);             //statically
    node*head=&n1;
    node n2(20);
    n1.next=&n2;
    node n3(30);
    n2.next=&n3;
    node n4(40);
    n3.next=&n4;
    node*n1=new node(10);        //dynamically
    node*head=n1;
    node * n2=new node(20);
    n1->next=n2;
    node*n3=new node(30);
    n2->next=n3;
    node*n4=new node(40);
    n3->next=n4;

    n1->print(head);*/

}