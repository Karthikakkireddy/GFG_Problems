/*
    Problem Link - https://www.geeksforgeeks.org/problems/count-nodes-of-linked-list/1
    TC - O(n)
    SC - O(1)
*/

/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    int getCount(Node* head) {
        // Code here
        if(head == NULL)
        {
            return 0;
        }
        int count = 0;
        Node* currently = head; 
        
        while(currently != NULL)
        {
            currently  = currently -> next; 
            count++; 
        }
        return count;
    }
};