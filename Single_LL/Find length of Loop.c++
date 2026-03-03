/*
    Problem link - https://www.geeksforgeeks.org/problems/find-length-of-loop/0

*/
/*
    Find Length of Loop — Floyd’s Cycle Detection

    Idea:

    Step 1: Detect if a cycle exists
    --------------------------------
    • Use two pointers:
        - slow moves 1 step
        - fast moves 2 steps
    • If they meet → cycle exists
    • If fast reaches NULL → no cycle

    Step 2: Count length of the cycle
    ----------------------------------
    Once slow and fast meet inside the loop:
    • Keep one pointer fixed
    • Move the other pointer one step at a time
    • Count steps until it reaches the same node again

    Why this works:
    After meeting, both pointers are inside the loop.
    Moving around until we return to the same node
    gives exactly one full cycle length.


    Time Complexity: O(N)
    - Detecting cycle takes linear time.
    - Counting loop length takes at most C steps (cycle length).
    - Overall still linear.

    Space Complexity: O(1)
    - Only two pointers used.
    - No extra memory.

    Edge Cases:
    ✔ empty list
    ✔ no cycle
    ✔ single node with self-loop
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
    int lengthOfLoop(Node *head) {
        // code here
        Node* slow = head ; 
        Node* fast = head ;
        
        int length ;
        while(fast != NULL && fast -> next != NULL)
        {
            slow = slow -> next;
            fast = fast -> next -> next ; 
            
            if(fast == slow)
            {
                
                do{
                   
                    length++;
                    fast = fast -> next;
                }while(fast != slow);
                
                return length;
            }
        }
        return length;
    }
};