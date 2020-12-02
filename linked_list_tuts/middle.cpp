#include <iostream>

using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int d)
    {
        data = d;
        next = NULL;
    }
};

class linked_list
{
    node *head, *tail;

public:
    linked_list()
    {
        head = NULL;
        tail = NULL;
    }

    void insert(int d)
    {
        if (head == NULL)
        {
            head = new node(d);
            head->next = tail;
            tail = head;
            tail->next = NULL;
            return;
        }
        node *temp = new node(d);
        tail->next = temp;
        tail = tail->next;
    }

    void print()
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ->";
            temp = temp->next;
        }
        cout << endl;
    }

    void middle()
    {
        if (head == NULL or head->next == NULL)
            return;

        node *slow = head;
        node *fast = head->next;

        while (fast != NULL and fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        cout<<slow->data<<endl;
    }
};

int main()
{
    linked_list l;
    int n;
    cout<<"how many elements you want to enter: ";
    cin>>n;
    for(int i=0;i<n;i++){
        int d;
        cin>>d;
        l.insert(d);
    }
    cout<<endl;
    cout<<"Linked list is: ";
    l.print();
    l.middle();

    return 0;
}