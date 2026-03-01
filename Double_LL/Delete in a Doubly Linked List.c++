/*
    Problem Link - https://www.geeksforgeeks.org/problems/delete-node-in-doubly-linked-list/0
    TC - O()
    SC - O(1)
*/

/* Structure of Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/

class Solution {
  public:
    Node* delPos(Node* head, int x) {
        // code here
        Node* curr  = head;
        if(x == 1)
        {
            head = curr-> next;
        }
        
        while(--x)
        {
            curr = curr -> next;
        }
        
        if(curr-> prev != NULL)
            curr -> prev -> next = curr -> next; 
        if(curr-> next != NULL)
          curr -> next -> prev = curr -> prev;
        delete curr;
        
        return head;
    }
};