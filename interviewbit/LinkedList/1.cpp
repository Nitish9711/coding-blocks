#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define null NULL
#define vi vector<int>
#define vl vector<ll>
#define moi map<int, int>
#define umoi unordered_map<int, int>
#define mol map<ll, ll>
#define umol unordered_map<ll, ll>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define psi pair<string, int>
#define pis pair<int, string>
#define vp vector<pair<int, int>>
#define val data
#define node ListNode
void ReadCP()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
class node{
    public:
    int data;
    node* next;
    node(int d){
        data = d;
        next = null;
    }
};
void print(node *head){
    if(head == null){
        cout<<endl;
        return ;
    }
    cout<<head->data<<" ->";
    print(head->next);

}
void insertAtHead(node* &head, int d){
    if(head == null){
        head = new node(d);
        return;
    }
    node *n = new node(d);
    n->next = head;
    head = n;
}

void insertAtEnd(node *&head, int d)
{
    if(head == null)
    {
        head = new node(d);
        return ;
    }
    node *temp = head;
    while(temp->next!= null)
        temp = temp->next;

    temp->next = new node(d);

}
int length(node *head){
    int len = 0;
    while (head!= null)
    {
        head = head->next;
        len++;
    }
    return len;
}
void insertInMiddle(node *&head, int d, int p){
    if(head == null or p == 0){
        insertAtHead(head, d);
        return;
    }
    else if(p > length(head))
    {
        insertAtEnd(head, d);
        return;
    }
    int jump = 1;
    node*temp = head;
    while(jump<=p-1){
        temp = temp->next;
        jump++;
    }
    node *n = new node(d);
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
void deleteTail(node*&head){
    if(head == null)
        return;

    node *temp =head;
    while(temp->next->next!= null)
        temp = temp->next;

    node *prev = temp;
    delete(temp->next);
    prev ->next= null;
}

void deleteInMiddle(node *&head, int pos){
    if(head == null)
        return;

    if(pos == 0)
        deleteHead(head);
    
    else if(pos == length(head))
        deleteTail(head);
    else{
        node*temp = head;
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

bool search(node *head, int d){
    node *temp = head;
    while(temp!= null){
        if(temp->data == d)
            return true;
        temp = temp->next;
    }
    return false;
}

bool recSearch(node *head , int d){
    if(head == null)
        return false;

    if(head->data = d)
        return true;

    return recSearch(head->next,d );
}

node *take_input(){
    int d;
    cin>>d;
    node *head= null;
    while(d!=-1){
        insertAtEnd(head,d);
        cin>>d;
    }

    return head;
}

node *take_input_from_file(){
    fstream file;
    file.open("input.txt");
    int d;
   
    node *head = null;
    while(file>>d){
        insertAtEnd(head, d);
    }
    return head;
}

// ostream& operator<<(ostream &os, node* head){
//     print(head);
//     return os;
// }

// istream& operator>>(istream & is, node*&head){
//     head = take_input_from_file();
//     return is;
// }

void reverse(node *&head){
    node *c = head;
    node *p = null;
    node *n;
    while(c!= null){
        n = c->next;
        c->next = p;
        p = c;
        c = n;
    }

    head = p;

}

node * optimized_reverse(node *&head){
    if(head == null || head->next == null)
        return head;

    node * shead = optimized_reverse(head->next); 
    node*temp = head->next;
    temp->next = head;
    head->next = NULL;
    return shead;
}

node *recReverse(node *head){
    if(head->next == null || head == null)
        return head;

    node *shead = recReverse(head->next);
    node *temp = shead;
    while(temp->next!= null){
        temp = temp->next;
    }
    head->next = null;
    temp->next = head;
    return shead;
}


node *midPoint(node*head){
    node* slow =head;
    node *fast =head->next;

    while(fast!= null and  fast->next != null){
        fast = fast->next->next;
        slow =slow->next;
    }
    return slow;
}


node *k_thNodeFromEnd(node *&head , int k){
    node *slow = head;
    node *fast = head;
    int i =0;
    while(i<k){
        if(fast == null){
            cout<<"out of range"<<endl;
            return slow;
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
        c = b;
        c->next = merge(a, b->next);
    }
    return c;
}
node* merge_sort(node*head){
    if(head == NULL or head->next == NULL)
    return head;

    node *mid = midPoint(head);
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
    node *fast  = head;
    node *slow =head;
    while(fast!= null && fast->next != null){
        fast = fast->next->next;
        slow =slow->next;
        if(fast == slow)
        {
            removeCycle(slow, fast);
            return true;
        }

    }
    return false;
}

node *part(node *head, int x){
    if(head == null || head->next == null)
        return head;

    node *temp = head;
    while(temp!= null){
        if(temp->val == x)
            break;

        temp = temp->next;        
    }
    if(temp->val !=  x)
        return head;


    // cout<<temp->val<<endl;
    
    node *less = head;
    cout<<less->val<<endl;
    // cout<<temp->next<<endl;
    node *great = temp;
    cout<<great->val<<endl;
    node *greatHead = great;
    cout<<greatHead->val<<endl;
    temp = head;
    cout<<temp->val<<endl;
    print(temp);
    print(less);
    print(great);
    while(temp != null){
        if(temp->val < x)
        {
            less->next = temp;
            cout<<"addingt to less "<<temp->data<<endl;
            less = less->next;
        }
        else{
             great->next =temp;
            cout<<"addingt to great "<<temp->data<<endl;
            great =great->next;
        }

         temp = temp->next;
        cout<<temp->val<<endl;
    }
            // temp = temp->next;

    // less->next = great;

    return head;
}


void insert(node *&head, node *newnode){
     ListNode*curr;
    if(head==NULL || head->val>=newnode->val)
    {
        newnode->next=head;
        head=newnode;
    }
    else
    {
        curr=head;
        while(curr->next && curr->next->val<newnode->val)
        {
            curr=curr->next;
        }
        newnode->next=curr->next;
        curr->next=newnode;
    }
}
void sortedinsert(ListNode*&head,ListNode*newnode)
{
    ListNode*curr;
    if(head==NULL || head->val>=newnode->val)
    {
        newnode->next=head;
        head=newnode;
    }
    else
    {
        curr=head;
        while(curr->next && curr->next->val<newnode->val)
        {
            curr=curr->next;
        }
        newnode->next=curr->next;
        curr->next=newnode;
    }
    
}
node* insertionSortList(node *&head){
    node *cur = head;
    node *sorted = NULL;
    while(cur!= null){      
        node * n = cur->next;
        insert(sorted, cur);
       cur = n;
    }
    head = sorted;
    print(sorted);
    return head;
}

ListNode* reverseBetween(ListNode* head, int m, int n) {
    node * newNode = new node(0);
    newNode->next = head;
    head= newNode;
    node *temp = head;
    int cnt = 1;
    while(cnt<m){
        temp = temp->next;
        cnt++;
    }
    // cout<<temp->data<<endl;
    node *cur= temp->next;
    node *pre =null;
    node *nxt;
    while(cnt <=n){
        nxt = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nxt;
        cnt++;
    }

    temp->next->next = cur;
    temp ->next = pre;

    return head->next;
}


node *reverseSub(node *head){
       node *c = head;
    node *p = null;
    node *n;
    while(c!= null){
        n = c->next;
        c->next = p;
        p = c;
        c = n;
    }

    head = p;
    return head;
}

node *mergeTwo(node *a, node *b){
    node *head = a;
    while(b!= null){
        node *a_next = a->next;
        node * b_next= b->next;
        a->next = b;
        b->next = a_next;
        b = b_next;
        a = a_next;

    }

    return head;
}
ListNode* reorderList(ListNode* head) {
    if(head== null || head->next == null)
        return head;
    node *temp = head;
    node *fast = head->next;
    node *slow =head;
    while(fast!= null){
        fast = fast->next;
        if(fast!= null){
            slow = slow->next;
            fast = fast->next;
        }
    }

    // cout<<fast->data<<endl;
    // cout<<slow->data<<endl;
    node *nxt  = slow->next;
    slow->next = null;
    nxt = reverseSub(nxt);
    // print(nxt);
    
    return mergeTwo(head, nxt);
}
node *deleteDuplicates(node *head){
    if(head == null || head->next == null)
        return head;

    node * newNode = new node(0);
    newNode->next = head;
    // head = newNode;
    
    node *pre = newNode;
    node *cur = head;
    while(cur!= null){
        while(cur->next && cur->data == cur->next->data){
            cur = cur->next;
        }
        if(pre->next == cur)
        {
            pre = pre->next;
        }
        else{
            pre->next = cur->next;
        }
        cur = cur->next;

    }


    return newNode->next;
}
node *reverseList(node *head, int k){
    if(head == null )
        return head;

    int cnt = 1;
    node *p = null;
    node * c= head;
    node *n= head;
    while(c!= null){
        while(cnt<k){
            n = n->next;
            cnt++;
        }
        cnt = 1;
        node *temp = n->next;
        n->next = p;
        p = c;
        c = temp;
        n = temp;
    }

    reverse(p);
    return p;
}


node *rotateRight(node *head, int k){

    int len = length(head);
    if(k == 0 || head == null || k == len)
        return head;
    int cnt =1;
    node *temp = head;
   
    while(cnt<len-k)
    {
        temp = temp->next;
        cnt++;
    }
    node *nxt = temp->next;
    node *temp2 = temp->next;
    temp->next = null;

    while(nxt->next!= null){
        nxt = nxt->next;
    }
    nxt->next = head;
    // print(nxt);


    return temp2;

    
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ReadCP();
  
    node *head = null;
  
    head = take_input();
   
    
    // insertAtEnd(head, 4);
    // insertAtEnd(head, 3);
    // insertAtEnd(head, 2);
    // insertAtEnd(head, 10);
    // insertAtEnd(head, 12);
    // insertAtEnd(head, 5);
    // insertAtEnd(head, 6);
    print(head);
    head  = rotateRight(head,90);
    print(head);
  
    return 0;
}