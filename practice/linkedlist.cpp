#include<bits/stdc++.h>
using namespace std;
#define null NULL
class node{
    public:
    int data;
    node*next;
    node(int d){
        data = d;
        next = null;
    }
};
void print(node *head){
    if(head == null){
        cout<<endl;
        return;
    }
    cout<<head->data<<" ->";
    print(head->next);
}
void insertAthead(node *head, int d){
    if(head == null)
    {
        head = new node(d);
        return;
    }
    node * n= new node(d);
    n->next = head;
    head =n;
}
void insertAtEnd(node *head, int d){
    if(head == null){
        head = new node(d);
        return;
    }
    node * temp = head;
    while(temp->next != null)
        temp = temp->next;
    temp->next = new node(d);
}

int length( node *head){
    int len =0;
    while(head != null){
        head = head->next;
        len++;
    }
    return len;
}
void insertInMiddle(node *&head, int d, int p){
    if(head == null or p == 0){
        insertAthead(head, p);
        return ;
    }
    else if(p > length(head)){
        insertAtEnd(head, d);
        return;
    }
    int jump = 1;
    node *temp = head;
    while(jump < p){
        temp = temp->next;
        jump++;
    }
    node * n  = new node(d);
    n->next = temp->next;
    temp->next = n;
    return;
}

void deleteHead(node *&head){
    if(head == null)
        return;
    node *temp = head->next;
    delete head;
    head = temp;
}
void deleteTail(node *&head){
    if(head == null){
        return;
    }
    node* temp = head;
    while(temp->next ->next != null){
        temp = temp->next;
    }
    node*prev = temp;
    delete(temp->next);
    prev->next = null;
}
void deleteInmiddle(node*&head, int pos)
{
    if(head == null)
        return;
    if(pos == 0)
        deleteHead(head);
    else if(pos== length(head)){
        deleteTail(head);
    }
    else{
        node*temp = head;
        for(int i=0;i<pos-1;i++){
            temp = temp->next;
        }
        if(temp == null or temp ->next == null){
            return;
        }
        node * n = temp->next;
        temp->next = n->next;
        delete n;
    }
}
bool search(node*head, int d){
    node * temp = head;
    while(temp!= null){
        if(temp->data == d){
            return true;
        }
        temp = temp->next;
    }
    return false;
}
bool recSearch(node *head, int d){
    if(head == null){
        return false;
    }
    if(head->data == d){
        return true;
    }
    return recSearch(head->next, d);
}

node * take_input(){
    int d;
    cin>>d;
    node*head = null;
    while(d!=-1){
        insertAtEnd(head, d);
        cin>>d;
    }
    return head;
}
node * take_input_form_file(){
    fstream file;
    file.open("input.txt");
    int d;
    node*head = null;
    while(file>>d){
        insertAtEnd(head, d);
    }
    file.close();
    return head;
}

// ostream& operator <<(ostream &os, node*head){
//     print(head);
//     return os;
// }

istream& operator >> (istream&is, node*&head){
    head = take_input_form_file();
    return is;
}
void reverse(node*&head){
    node * c = head;
    node * p = null;
    node*n ;
    while(c!=null){
        n = c->next;
        c->next = p;
        p = c;
        c = n;
    }
    head = p;
}
node*recursiveReverse(node*head){
    if(head->next ==null || head == null){
        return head;
    }
    node * shead = recursiveReverse(head->next);
    node *temp = shead;
    while(temp->next != null){
        temp = temp->next;
    }
    head->next = null;
    temp->next = head;
    return shead;
}
node * optimizedReverse(node *head){
    if(head->next ==null || head == null){
        return head;
    }
    node *shead = optimizedReverse(head->next);
    node * temp = head->next;
    temp->next = head;
    head->next = null;
    return shead;
}
node* midPoint(node*head){
    node *slow= head;
    node*fast = head->next;
    while(fast!= null and fast->next != null){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
node* k_thnodeFromEnd(node *&head, int k){
    node *slow =head;
    node*fast = head;
    int i =0;
    while(i<k){
        if(fast == null){
            cout<<"out of range"<<endl;
        }
        fast = fast->next;
        i++;
    }
    while(fast!= null){
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}
node *merge(node *a, node *b){
    if(a == null)
        return b;
    if( b== null)
        return a;
    node *c;
    if(a->data < b->data){
        c = a;
        c->next = merge(a->next, b);
    }
    else{
        c= b;
        c->next = merge(a, b->next);
    }
    return c;
}
node *merge_sort(node *head){
    if(head == null or head->next == null){
        return head;
    }
    node*mid = midPoint(head);
    node*a  = head;
    node*b = mid->next;
    mid->next = null;
    a= merge_sort(a);
    b = merge_sort(b);
    node* c=merge(a, b);
    return c;
}
void removeCycle(node *slow , node*fast){
    while(slow ->next != fast ->next){
        slow  = slow->next;
        fast = fast->next;
    }
    fast->next = null;
}
bool detectCycle(node *head){
    node *fast =head;
    node*slow = head;
    while(fast!= null && fast->next != null){
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow){
            removeCycle(head, fast);
            return true;
        }
    }
    return false;
}
node* insert(node* head, node*temp){
    if(head == null || head->data >= temp->data){
        temp->next = head;
        return temp;
    }
    node* parse = head;
    while(head->next!= null && head->next->data < temp->data){
        head = head->next;
    }
    temp->next = head->next;
    head->next = temp;
    return parse;
}
void insertionSort(node*&head){
    node *result = null;
    while(head!= null){
        node *temp = head->next;
        result = insert(result, head);
        head =temp;
    }
    head = result;
}


int main(){

    return 0;
 }