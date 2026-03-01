/*
    Problem Link - https://www.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/0
    TC - O(N)
    SC - O(1)
*/

/*
class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

*/

// void traverseLL(Node* head, vector<int> &v)
// {
//     Node* temp = head;
    
//     if(temp == NULL)
//     {
//         return ;
//     }
//     while(temp != NULL)
//     {
//         v.emplace_back(temp->data);
//         temp = temp -> next; 
//     }
//     return;
// }
class Solution {
  public:
    Node *reverse(Node *head) {
        // code here
        // vector<int> v;
        
        // traverseLL(head, v);
        
        // Node* temp = head; 
        
        // for(int i= v.size()-1; i>=0 ; i--)
        // {
        //     temp ->data  = v[i];
        //     temp = temp -> next;
        // }
        
        
        Node* curr = head; 
        
        while(curr != NULL)
        {
            swap(curr -> next, curr -> prev);
            if(curr-> prev == NULL)
            {
                head = curr;
            }
            curr = curr-> prev;
        }
        return head;
    }
};