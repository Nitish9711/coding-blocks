#include<bits/stdc++.h>
using namespace std;
#define data val
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};//O(N) space
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*>mp;
        Node*cur= head;
        Node *clone;
        while(cur){
            Node * temp = new Node(cur->data);
            mp[cur] = temp;
            cur = cur->next;
        }
        
        cur = head;
        while(cur){
            clone = mp[cur];
            clone->next = mp[cur->next];
            clone->random = mp[cur->random];
            cur= cur->next;
        }
        return mp[head];
    }
};
// O(1) space  insert the new nodes betwenn the nodes then extract them
// A linked list node with a random pointer
struct Node
{int data;
    Node* next;
    Node* random;
    Node(int data)
    { this->data = data;
    this->next = nullptr;
    }
    Node() {}
};
// Function to clone a linked list having random pointers
Node* cloneLinkedList(Node* head)
{
    /* 1. Create a duplicate of each node of the original linked list */
 
    // traverse the original linked list
    Node* curr = head;
    while (curr != nullptr)
    {
        // take a pointer to the next node in the original list
        Node* next = curr->next;
 
        // duplicate each node of the linked list
        Node* dup = new Node(curr->data);
 
        // associate each duplicate node with the next child of the original node
        curr->next = dup;
        dup->next = next;
 
        // advance to the next node in the original list
        curr = next;
    }
 
    /* 2. Update the random pointers of the duplicated nodes */
 
    // traverse the modified list
    curr = head;
    while (curr != nullptr)
    {
        // if a random pointer for the original node exists, set it for the clone
        if (curr->random != nullptr) {
            (curr->next)->random = (curr->random)->next;
        }
 
        // advance to the next node in the original list
        curr = (curr->next)->next;
    }
 
    /* 3. Extract the duplicate nodes from the modified list */
 
    // construct a dummy node whose next pointer points to the head
    // of the cloned linked list
    Node dummy;
 
    // maintain a tail node for the clone
    Node* tail = &dummy;
 
    // traverse the modified list
    curr = head;
    while (curr != nullptr)
    {
        // take a pointer to the next node in the original list
        Node* next = curr->next->next;
 
        // extract the duplicate
        Node* dup = curr->next;
        tail->next = dup;
        tail = dup;
 
        // restore the original linked list
        curr->next = next;
 
        // advance to the next node in the original list
        curr = next;
    }
 
    // return head node of the cloned list
    return dummy.next;
}