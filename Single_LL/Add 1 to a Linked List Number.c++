/*
    Link : https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1
*/


/*

    TC - O(3N)
    - Reverse LL - O(N)
    - Adding nodes - O(N)
    - Reversing back the new LL - O(N)

    SC - O(N)
    - New LL for the answer (We can actually modify the existing LL)
*/

/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
  
    Node* reverseLL(Node* head)
    {
        if(head == NULL || head-> next == NULL)
        {
            return head;
        }
        Node* prev = NULL;
        Node* curr = head;
        Node* front = head -> next;
        
        while(curr != NULL)
        {
            curr -> next = prev; 
            prev = curr ;
            curr = front;
            
            if(front != NULL)
            {
                front = front -> next;
            }
        }
        return prev;
    }
    Node* addOne(Node* head) {
        // Your Code here
        head = reverseLL(head);
        
        int carry =1 ; 
        
        Node* temp = head ;
        Node* dummy = new Node(-1);
        Node* curr = dummy;
        while(temp != NULL)
        {
            Node* newNode = new Node((temp -> data + carry)%10);
            curr -> next = newNode; 
            curr = newNode; 
            
            carry = (temp -> data + carry)/10 ;
            
            temp = temp -> next;
            if(temp == NULL && carry)
            {
                newNode = new Node(1);
                curr -> next = newNode;
            }
        }
        head = reverseLL(dummy -> next);
        // return head of list after adding one
        return head;
    }
};


/*
    Approach:
    - Reverse the linked list so that we can process the least
      significant digit first.
    - Traverse the reversed list and add 1 while propagating carry.
    - Update the node values directly.
    - If a carry remains at the last node, create one extra node.
    - Reverse the list again to restore the original order.

    Time Complexity: O(N)
    - Reverse the list → O(N)
    - Traverse to add digits → O(N)
    - Reverse back → O(N)
    - Total ≈ 3N → O(N)

    Space Complexity: O(1)
    - We modify the existing linked list without using
      additional data structures.
*/
class Solution {
  public:
  
    Node* reverseLL(Node* head)
    {
        if(head == NULL || head-> next == NULL)
        {
            return head;
        }
        Node* prev = NULL;
        Node* curr = head;
        Node* front = head -> next;
        
        while(curr != NULL)
        {
            curr -> next = prev; 
            prev = curr ;
            curr = front;
            
            if(front != NULL)
            {
                front = front -> next;
            }
        }
        return prev;
    }
    Node* addOne(Node* head) {
        // Your Code here
        head = reverseLL(head);
        
        Node* current = head; 
        int carry = 1 ;
        
        while(current != NULL)
        {
            int sum = (current -> data + carry );
            current -> data = sum%10;
            carry = sum / 10;
            
            if(current ->next == NULL && carry)
            {
                current -> next = new Node(1);
                carry =0;
            }
            
            current = current -> next; 
        }
        head = reverseLL(head);
        // return head of list after adding one
        return head;
    }
};




/*
    Approach:
    - Use recursion to reach the last node of the linked list.
    - Start by adding 1 to the last digit.
    - While returning from recursion, propagate the carry
      to the previous nodes and update their values.
    - If a carry remains after processing the head node,
      create a new node at the front.

    Why This Works:
    - Recursion allows us to process the linked list from
      right to left (least significant digit first) without
      reversing the list.

    Time Complexity: O(N)
    - Each node is visited exactly once.

    Space Complexity: O(N)
    - Due to recursion stack used during the function calls.
*/

/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
  
   
    int addLL(Node* head, int carry)
    {
        if(head -> next == NULL)
        {
            int sum = head -> data + carry;
            head -> data = sum % 10;
            return sum / 10;
        }
        carry = addLL(head -> next,1);
        int sum = head -> data + carry;
        head -> data = sum % 10;
        return sum/10;
    }
    Node* addOne(Node* head) {
        // Your Code here
        int carry = addLL(head, 1);
        if(carry)
        {
            Node* newNode = new Node(1);
            newNode -> next = head;
            head = newNode;
        }
        return head;
    }
};



/*
    Approach: Recursion

    Idea:
    - Recursively go to the end of the linked list.
    - Add 1 to the last node.
    - While returning from recursion, propagate the carry
      to previous nodes and update their values.

    Why This Works:
    - Recursion processes nodes from right to left
      (least significant digit first) without reversing the list.

    How This Is Different From The Previous Recursive Version:
    - Earlier version had a separate condition to detect the last node.
    - In this version, the base case returns 1 when head becomes NULL.
    - This automatically introduces the initial carry and simplifies the logic.
    - As recursion returns, the carry naturally propagates through the list.

    Time Complexity: O(N)
    - Each node is processed once.

    Space Complexity: O(N)
    - Due to recursion stack.
*/
class Solution {
  public:
  
    int oneAdd(Node* head)
    {
        if(head == NULL)
            return 1;
        
        int carry = oneAdd(head -> next);
        int sum = carry + head -> data;
        head -> data = sum % 10;
        
        return sum/10;
    }
    Node* addOne(Node* head) {
        // Your Code here
       
       int carry = oneAdd(head);
       if(carry)
       {
           Node* newNode = new Node(1);
           newNode -> next = head;
           head= newNode;
       }
       return head;
    }
};

