/*
    Problem Link - https://www.geeksforgeeks.org/problems/search-in-linked-list/0
    TC - O(n)
    SC - O(1)
*/

/*
struct Node
{
    int data;
    Node * next;
    Node (int x)
    {
        data=x;
        next=NULL;
    }

};
*/
class Solution {
  public:
    bool searchLinkedList(Node *head, int x) {
        // Your code here
        Node* current = head;
        while(current != NULL )
        {
            if(current -> data == x)
                return true;
            current = current -> next;
        }
        return false;
    }
};