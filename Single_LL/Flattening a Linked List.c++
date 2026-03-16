/*
    Problem Link - https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1
*/
/*
    Problem Understanding

    Each node has:
        next   → points to the next column
        bottom → points downwards within a column

    Example structure:

        5 → 10 → 19 → 28
        |    |     |     |
        7    20    22    35
        |          |     |
        8          50    40
        |                |
        30               45

    Goal:
    Convert this 2D structure into a single sorted list using the
    bottom pointer.
* /


/*
 
------------------------------------------------------------

    Overall Idea

    Step 1: Flatten the structure
        Connect all bottom chains together so that the structure
        becomes one long bottom-linked list.

    Step 2: Sort the resulting list
        Use merge sort on the bottom pointers.

------------------------------------------------------------

    Step 1: Flattening

    In flatten():

        while(headTemp != NULL)
        {
            Node* nextHeadTemp = headTemp->next;
            Node* currentLastChildNode = getLastNode(headTemp);
            currentLastChildNode->bottom = nextHeadTemp;
        }

    What this does:

    For every column head:
        - find the last node in that column
        - attach the next column head to its bottom

    Example transformation:

        5 → 10 → 19

    becomes

        5
        |
        7
        |
        8
        |
        30
        |
        10
        |
        20
        |
        19
        |
        ...

    So the 2D structure becomes one vertical linked list.

------------------------------------------------------------

    Step 2: Sorting the list

    After flattening, the list is NOT sorted.

    So we run merge sort using bottom pointers.

------------------------------------------------------------

    How sortList() works

    It is a standard merge sort on a linked list.

    1. Find middle using slow/fast pointer
    2. Split list into two halves
    3. Recursively sort both halves
    4. Merge the two sorted halves

------------------------------------------------------------

    mergeLL()

    This merges two sorted bottom-linked lists
    exactly like merging two sorted linked lists.

------------------------------------------------------------

    Time Complexity

    Let:
        N = number of top nodes
        M = total number of bottom nodes across all lists

    Flattening step:
        We traverse each bottom list once
        → O(N + M)

    Sorting step (merge sort):
        Merge sort takes
        → O((N + M) log(N + M))

    Total Time Complexity:

        O((N + M) log(N + M))

------------------------------------------------------------

    Space Complexity

    Recursion stack from merge sort:

        O(log(N + M))

------------------------------------------------------------

    Key Insight

    Instead of merging columns one by one,
    this solution first converts the structure into
    a single linked list and then applies merge sort.

    That is why it may look complicated,
    but conceptually it is just:

        flatten → sort
*/
class Solution {
  public:
  
    Node* findMiddle(Node* head )
    {
        Node* slow = head ;
        Node* fast = head;
        
        while(fast -> bottom != NULL && fast -> bottom -> bottom != NULL)
        {
            slow = slow -> bottom ;
            fast = fast -> bottom ;
        }
        return slow;
    }
    
    
    Node* mergeLL(Node* first , Node* second)
    {
        Node* a = first;
        Node* b = second;
        Node* dummy = new Node(-1);
        Node* temp = dummy; 
        
        while(a!= NULL && b!= NULL)
        {
            if(a-> data <= b-> data )
            {
                temp -> bottom = a ;
                temp = a;
                a = a -> bottom ;
            }
            else
            {
                temp -> bottom = b;
                temp = b;
                b = b-> bottom;
            }
        }
        if(a!= NULL)
        {
            temp -> bottom = a ;
        }
        if(b != NULL )
        {
            temp -> bottom = b;
        }
        return dummy -> bottom ;
    }
    
    
    Node* sortList(Node* head )
    {
        if(head == NULL || head -> bottom == NULL)
        {
            return head;
        }
        Node* mid = findMiddle(head);
        
        Node* firstHalfHead = head ;
        Node* secondHalfHead = mid -> bottom ;
        
        mid -> bottom = NULL;
        
        firstHalfHead =  sortList(firstHalfHead);
        secondHalfHead =  sortList(secondHalfHead);
        
        return mergeLL(firstHalfHead, secondHalfHead);
        
    }
    
    Node *getLastNode(Node* head )
    {
        Node* temp = head ;
        while(temp-> bottom != NULL)
        {
            temp = temp -> bottom;
        }
        return temp;
    }
    
    
    Node *flatten(Node *root) {
        // code here
        Node* headTemp = root;
        
        while(headTemp != NULL)
        {
            Node* nextHeadTemp = headTemp -> next; 
            Node* currentLastChildNode = getLastNode(headTemp);
            currentLastChildNode -> bottom = nextHeadTemp;
            
            headTemp = headTemp -> next; 
        }
        
        return sortList(root);
    }
};



/*
    Approach: Iterative Merging of Vertical Lists

    Idea:
    - Each node in the top list points to another sorted list using
      the bottom pointer.
    - We repeatedly merge the current flattened list with the next
      vertical list until all columns are merged.

    Example structure:

        5 → 10 → 19
        |    |     |
        7    20    22
        |          |
        8          50

    Step 1:
        Merge list starting at 5 with list starting at 10.

    Step 2:
        Merge the result with list starting at 19.

    Continue until no next column remains.

------------------------------------------------------------

    mergeLL()

    - Merges two sorted bottom-linked lists.
    - Similar to merging two sorted linked lists.
    - We compare nodes and attach the smaller one using
      the bottom pointer.

------------------------------------------------------------

    Why pointer updates are needed

    headTemp:
        points to the current merged list.

    nextTemp:
        points to the next column that needs to be merged.

    After merging:
        - If the merged head remains headTemp, we simply move
          nextTemp forward.
        - If nextTemp becomes the new head, we update headTemp.

    The 'next' pointers are cleared because the flattened list
    should only use bottom pointers.

------------------------------------------------------------

    Time Complexity: O(N * 2M)

    Let:
        N = number of head nodes (horizontal)
        M = number of nodes verticall.

    - For each N. Two Vertical nodes are been merged.

------------------------------------------------------------

    Space Complexity: O(1)

    - No extra data structures are used.
    - Only a few pointer variables are maintained.
*/

class Solution {
  public:
    Node* mergeLL(Node* first , Node* second)
    {
        Node* a = first;
        Node* b = second;
        Node* dummy = new Node(-1);
        Node* temp = dummy; 
        
        while(a!= NULL && b!= NULL)
        {
            if(a-> data <= b-> data )
            {
                temp -> bottom = a ;
                temp = a;
                a = a -> bottom ;
            }
            else
            {
                temp -> bottom = b;
                temp = b;
                b = b-> bottom;
            }
        }
        if(a!= NULL)
        {
            temp -> bottom = a ;
        }
        if(b != NULL )
        {
            temp -> bottom = b;
        }
        return dummy -> bottom ;
    }    
    Node *flatten(Node *root) {
        // code here
        if(root == NULL)
            return root;
        Node* headTemp = root;
        Node* nextTemp = root -> next ;
        while(nextTemp != NULL)
        {
           Node* newHead = mergeLL(headTemp, nextTemp);
           
           if(newHead == headTemp)
           {
               headTemp -> next = nextTemp -> next;
           }
           else if(newHead == nextTemp)
           {
               headTemp = nextTemp;
               nextTemp -> next = NULL;
               
           }
           nextTemp = headTemp -> next; 
           headTemp -> next = NULL;
        }
        
        return headTemp;
    }
};

/*
    Approach: Recursive merging of columns

    Idea:
    - Each node in the top list represents a sorted vertical list
      using the bottom pointer.
    - We flatten the list from right to left.

    Steps:
    1. Recursively flatten the list starting from root->next.
       This gives a fully flattened list of all columns to the right.
    2. Merge the current column (root) with that flattened list.
    3. Return the merged list.

------------------------------------------------------------

    Example

        5 → 10 → 19
        |    |     |
        7    20    22
        |          |
        8          50

    Recursion flow:

        flatten(5)
            flatten(10)
                flatten(19)
                    return 19 column

            merge(10-column , 19-column)

        merge(5-column , merged result)

------------------------------------------------------------

    mergeLL()

    - Merges two sorted bottom-linked lists.
    - Similar to merging two sorted linked lists.
    - The smaller node is attached using the bottom pointer.

    We also set:
        temp->next = NULL
    to remove horizontal links so the final list uses only bottom pointers.

------------------------------------------------------------

    Time Complexity: O(M * N)

    where:
        N = number of horizontal lists
        M = average number of nodes per vertical list

    Reason:
    - Each recursive call merges the current column with
      the flattened result of all columns to the right.
    - Nodes can be visited multiple times across merges.

------------------------------------------------------------

    Space Complexity: O(N)

    - Recursion stack depth equals the number of horizontal nodes.
*/

class Solution {
  public:
    Node* mergeLL(Node* first , Node* second)
    {
        Node* a = first;
        Node* b = second;
        Node* dummy = new Node(-1);
        Node* temp = dummy; 
        
        while(a!= NULL && b!= NULL)
        {
            if(a-> data <= b-> data )
            {
                temp -> bottom = a ;
                temp = a;
                a = a -> bottom ;
            }
            else
            {
                temp -> bottom = b;
                temp = b;
                b = b-> bottom;
            }
            temp -> next = NULL;
        }
        if(a!= NULL)
        {
            temp -> bottom = a ;
        }
        if(b != NULL )
        {
            temp -> bottom = b;
        }
        return dummy -> bottom ;
    }
    
    Node *flatten(Node *root) {
        // code here
        if(root == NULL||root->next==NULL)
            return root;
        Node* nextHead = flatten(root -> next );
        Node* newHead = mergeLL(root, nextHead);
        
        return newHead;
    }
};