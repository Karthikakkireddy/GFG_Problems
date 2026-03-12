/*
    Problem link - https://www.geeksforgeeks.org/problems/remove-duplicates-from-a-sorted-doubly-linked-list/1
*/

/*
    Approach

    - The linked list is sorted, so duplicate values appear consecutively.
    - Traverse the list and keep track of the last unique node (firstEle).
    - If the current node has the same value, skip all nodes with that value.
    - Reconnect the last unique node to the next new unique node.

    This effectively removes duplicate nodes by adjusting the next
    and prev pointers instead of deleting nodes individually.

    ------------------------------------------------------

    Edge Case Dry Run

    Example:
        1 ⇄ 1 ⇄ 1 ⇄ 2 ⇄ 3 ⇄ 3

    Step 1:
        firstEle = 1
        temp moves while value == 1

        temp stops at 2

    Update links:
        firstEle->next = 2
        2->prev = firstEle

    List becomes:
        1 ⇄ 2 ⇄ 3 ⇄ 3

    Step 2:
        firstEle = 2

    Step 3:
        duplicates of 3 skipped

    Final list:
        1 ⇄ 2 ⇄ 3

    ------------------------------------------------------

    Why This Works

    - Since the list is sorted, duplicates always appear together.
    - By skipping the consecutive nodes with the same value,
      we can reconnect the previous unique node directly
      to the next unique node.

    ------------------------------------------------------

    Time Complexity: O(N)

    - Each node is visited at most once while skipping duplicates.

    ------------------------------------------------------

    Space Complexity: O(1)

    - No extra data structures are used.
    - Only a few pointer variables are maintained.
*/

class Solution {
  public:

    Node *removeDuplicates(struct Node *head) {
        // Your code here
        Node* temp = head ;
        Node* firstEle = NULL;
        int value = -1;
        
        while(temp != NULL)
        {
            if(temp -> data != value)
            {
                value = temp -> data;
                firstEle = temp;
                temp = temp -> next ;
            }
            else
            {
                while(temp != NULL && temp -> data == value)
                {
                    temp = temp -> next;
                }
                if(temp != NULL)
                {
                    temp -> prev = firstEle;
                }
                firstEle -> next = temp;
            }
        }
        return head;
    }
};

/*
    Approach

    - The linked list is sorted, so duplicate values appear
      next to each other.
    - For each node (temp), move another pointer (front)
      forward until we reach a node with a different value.
    - Connect temp directly to that node.
    - Update the prev pointer to maintain the doubly linked list.

    Essentially:
    - Skip all duplicate nodes between temp and front.

    ------------------------------------------------------

    Dry Run Example

    List:
        1 ⇄ 1 ⇄ 1 ⇄ 2 ⇄ 3 ⇄ 3

    Step 1:
        temp = first 1
        front moves until value != 1
        front stops at 2

        Update:
            temp->next = 2
            2->prev = temp

        List becomes:
            1 ⇄ 2 ⇄ 3 ⇄ 3

    Step 2:
        temp = 2
        front = 3 (no duplicates)

    Step 3:
        temp = first 3
        front skips duplicate 3
        front becomes NULL

        Update:
            temp->next = NULL

    Final list:
        1 ⇄ 2 ⇄ 3

    ------------------------------------------------------

    Why This Works

    - Since the list is sorted, duplicates always appear consecutively.
    - By skipping all nodes with the same value, we ensure
      only the first occurrence remains.

    ------------------------------------------------------

    Time Complexity: O(N)

    - Each node is visited at most once while skipping duplicates.

    Space Complexity: O(1)

    - Only pointer variables are used, no extra data structures.
*/

class Solution {
  public:

    Node *removeDuplicates(struct Node *head) {
        // Your code here
        Node* temp = head ;
        
        while(temp != NULL )
        {
            Node* front = temp -> next; 
            
            while(front != NULL && front -> data == temp -> data )
            {
                front = front -> next;
            }
            
            temp -> next = front ;
            if(front != NULL)
                front -> prev = temp;
            
            temp = temp -> next;
        }
        
        
        return head;
    }
};