/*
    Problem Link - https://www.geeksforgeeks.org/problems/insert-a-node-in-doubly-linked-list/0
    TC - O(N)
    SC - O(1)
*/


/*
class Node {
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = prev = nullptr;
    }
};
*/

class Solution {
  public:
    Node *insertAtPos(Node *head, int p, int x) {
        
        
    
        Node* curr = head;
        
        while(p--)
        {
            curr = curr-> next;
        }
        
        Node* newNode = new Node(x);
        
        newNode -> prev = curr;
        newNode -> next = curr -> next; 
        
        if(curr -> next != NULL)
        {
            curr -> next -> prev = newNode;
        }
        curr -> next = newNode;
        
        return head;
        
        
        
        
        
        // code here
        // if(p == 0)
        // {
        //     Node* newNode = new Node(x);
        //     newNode-> right = head;
            
        //     head->left = newNode;
            
        //     head = newNode;
        //     return head;
        // }
        
        // p = p+2;
        // Node* curr = head;
        // Node* previous = nullptr;
        // for(int i=1; (curr != NULL && previous!= NULL) ; i++)
        // {
        //     if(i==p)
        //     {
            
        //         Node* newNode = new Node(x);
        //         newNode-> prev = previous;
        //         newNode -> next = curr;
        //         if(i==1)
        //             head= newNode;
        //         if(previous != NULL)
        //              previous-> next = newNode; 
        //         if(curr != NULL)
        //              curr -> prev = newNode;
                
        //     }
        //     previous = curr;
        //     if(curr != NULL)
        //         curr = curr->next;
        // }
        // return head;
        
        
        
    }
};