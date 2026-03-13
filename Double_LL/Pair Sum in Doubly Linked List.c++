/*
    Problem link - https://www.geeksforgeeks.org/problems/delete-all-occurrences-of-a-given-key-in-a-doubly-linked-list/1
*/


/*
    Approach: Two Pointer Technique (from both ends)

    Idea:
    - Since the doubly linked list is sorted, we can use
      two pointers to find pairs with the given sum.

    Steps:
    1. Set two pointers:
            start → first node
            tail  → last node
    2. Compute the sum of the two nodes.
    3. If sum < target
            move start forward (need a bigger value).
    4. If sum > target
            move tail backward (need a smaller value).
    5. If sum == target
            store the pair and move both pointers.

    Why This Works:
    - The list is sorted.
    - Moving start increases the sum.
    - Moving tail decreases the sum.
    - This allows us to find pairs efficiently without
      checking every possible combination.

    Stopping Condition:
        stop when start meets or crosses tail.

    Time Complexity: O(N)
    - Each pointer moves at most N times.

    Space Complexity: O(1)
    - Only pointers are used (excluding the result vector).
*/
// User function Template for C++

/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

class Solution {
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        // code here
        vector<pair<int, int >> res;
       
        
        Node* start = head ;
        Node* tail = head ;
        while(tail -> next != NULL)
        {
            tail = tail -> next;
        }
        
        while(start != tail && tail-> next != start )
        {
            
            int sum = start -> data + tail -> data;
            
            if(target > sum)
            {
                start = start -> next;
            }
            else if (target < sum)
            {
                tail = tail -> prev;
            }
            else
            {
                res.emplace_back(start->data, tail -> data);
                start = start -> next ; 
                tail = tail -> prev;
            }
        }
        
        
        
        return res;
    }
};