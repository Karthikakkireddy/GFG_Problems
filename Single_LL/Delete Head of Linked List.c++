/*
    Problem Link - https://www.geeksforgeeks.org/problems/delete-head-of-linked-list/0
    TC - O(1)
    SC-O(1)
*/

/*
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  public:
    Node *deleteHead(Node *head) {
        // code here
        Node* currently = head;
        head = head -> next;
        delete currently;
        return head;
    }
};
