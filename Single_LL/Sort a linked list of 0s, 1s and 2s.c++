/*

    Problem link - https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1

*/


/*
    Approach: Three Dummy Lists

    Idea:
    - Create three temporary lists:
        one for 0s
        one for 1s
        one for 2s
    - Traverse the original list and attach each node
      to its corresponding list.
    - Finally connect the three lists together.

    Structure after traversal:
        0-list → 1-list → 2-list

    This keeps the original nodes and only changes pointers.

    ------------------------------------------------------

    Edge Cases (with dry run)

    Case 1: No 1s in the list
        Example:
            0 → 2 → 0 → 2

        After segregation:
            0-list: 0 → 0
            1-list: NULL
            2-list: 2 → 2

        Since 1-list is empty:
            zero → next = twodummy->next

        Final list:
            0 → 0 → 2 → 2

    ------------------------------------------------------

    Case 2: No 0s in the list
        Example:
            1 → 2 → 1 → 2

        After segregation:
            0-list: NULL
            1-list: 1 → 1
            2-list: 2 → 2

        zerodummy->next points to first non-zero node.
        Final list:
            1 → 1 → 2 → 2

    ------------------------------------------------------

    Case 3: No 2s in the list
        Example:
            0 → 1 → 0 → 1

        After segregation:
            0-list: 0 → 0
            1-list: 1 → 1
            2-list: NULL

        Connection:
            0-list → 1-list → NULL

        Final list:
            0 → 0 → 1 → 1

    ------------------------------------------------------

    Case 4: Single node
        Example:
            1

        Traversal places it in 1-list.
        After connecting lists:
            1

    ------------------------------------------------------

    Why Dummy Nodes Are Used

    - Dummy nodes simplify list construction.
    - They avoid checking whether a list is empty
      when inserting the first node.

    Example structure during processing:
        zerodummy → 0 → 0
        onedummy  → 1 → 1
        twodummy  → 2 → 2

    ------------------------------------------------------

    Why Dummy Nodes Are Deleted

    - Dummy nodes are temporary helper nodes.
    - They are not part of the final list.
    - Deleting them avoids unnecessary memory usage.

    ------------------------------------------------------

    What Happens If We Delete zero / one / two

    - zero, one, and two are just pointers pointing
      to nodes already inside the linked list.

    Example:

        zerodummy → 0 → 0
                      ↑
                    zero pointer

    If we call:
        delete zero;

    we would delete the actual node in the list,
    corrupting the final linked list.

    That is why we only delete:
        zerodummy, onedummy, twodummy

    ------------------------------------------------------

    Time Complexity: O(N)
    - We traverse the linked list once.

    Space Complexity: O(1)
    - Only a few pointers and three dummy nodes are used.
*/
    Approach: Three Dummy Lists

    Idea:
    - Create three temporary lists:
        one for 0s
        one for 1s
        one for 2s
    - Traverse the original list and attach each node
      to its corresponding list.
    - Finally connect the three lists together.

    Structure after traversal:
        0-list → 1-list → 2-list

    This keeps the original nodes but rearranges their links.

    ------------------------------------------------------

    Handling Edge Cases

    Case 1: No 1s in the list
        - If the 1-list is empty, we directly connect
          the 0-list to the 2-list.

    Case 2: No 0s
        - Then zerodummy->next will point directly to
          the first non-zero element when lists connect.

    Case 3: No 2s
        - The final connection still works because
          the 2-list will just be NULL.

    Case 4: Single node list
        - The traversal still works and returns the same node.

    ------------------------------------------------------

    Why Dummy Nodes Are Used

    - Dummy nodes simplify list construction.
    - They avoid special cases when inserting the first element.
    - Without them we would need extra checks like:
            if(head == NULL)

    Example:
        zerodummy -> 0 -> 0 -> 0
        onedummy  -> 1 -> 1
        twodummy  -> 2 -> 2

    ------------------------------------------------------

    Why Dummy Nodes Are Deleted

    - The dummy nodes were only temporary helpers.
    - They are not part of the final list.
    - After connecting the lists, they are no longer needed,
      so deleting them frees memory and avoids leaks.

    ------------------------------------------------------

    What Happens If We Delete zero / one / two

    Important:
    - zero, one, and two are just POINTER VARIABLES
      that point to existing nodes in the list.
    - They are NOT newly allocated nodes.

    Example dry run:

        zerodummy → 0 → 0
        onedummy  → 1 → 1
        twodummy  → 2 → 2

        zero pointer → last 0 node
        one pointer  → last 1 node
        two pointer  → last 2 node

    If we call:

        delete zero;

    we would delete the last actual node of the list,
    which corrupts the final linked list.

    That is why we only delete:
        zerodummy, onedummy, twodummy

    and NOT the traversal pointers.

    ------------------------------------------------------

    Time Complexity: O(N)

    - We traverse the list once.
    - Each node is processed exactly one time.

    ------------------------------------------------------

    Space Complexity: O(1)

    - No extra data structures proportional to N are used.
    - Only three dummy nodes and a few pointers.
*/
class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        Node* zerodummy = new Node(0);
        Node* onedummy = new Node(1);
        Node* twodummy = new Node(2);
        
        Node* zero = zerodummy;
        Node* one = onedummy;
        Node* two = twodummy;
        
        Node* temp = head;
        
        while(temp != NULL)
        {
            if(temp -> data == 0)
            {
                zero-> next = temp;
                zero = temp;
            }
            else if(temp -> data == 1)
            {
                one -> next = temp;
                one = temp;
            }
            else
            {
                two -> next = temp;
                two = temp;
            }
            temp = temp -> next;
        }
        if(onedummy -> next !=NULL)
             zero -> next = onedummy -> next;
        else    
            zero -> next = twodummy -> next;
        one -> next = twodummy -> next; 
        two -> next = NULL;
        head = zerodummy -> next;
        
        
        delete onedummy;
        delete twodummy;
        delete zerodummy;
        // delete one;
        // delete two;
        // delete zero;
        
        return head;
    }
};