https://www.geeksforgeeks.org/problems/implement-stack-using-linked-list/1

/*
========================================================
🔴 Stack using Singly Linked List (Your Implementation)
========================================================

🧠 What you are trying to do:

- Implement a stack (LIFO)
- Using a linked list
- With:
    dummy → starting node
    curr  → points to TOP of stack

--------------------------------------------------------

📦 Structure

dummy → first node (sentinel)
curr  → last node (top of stack)

Example:

dummy → 10 → 20 → 30
                    ↑
                  curr (top)

--------------------------------------------------------

🟢 Constructor

    dummy = new Node(-1);
    curr = dummy;

👉 Empty stack looks like:

    dummy → NULL
    curr = dummy

--------------------------------------------------------

🟢 isEmpty()

    currSize == 0

👉 Correct and clean
👉 You are NOT relying on pointers → good

--------------------------------------------------------

🟢 push(x)

Steps:

1. Create new node
2. Attach it after curr
3. Move curr to new node
4. Increase size

Flow:

Before:
    dummy → 10 → 20
                    ↑ curr

Push(30):

    curr->next = newNode
    curr = newNode

After:
    dummy → 10 → 20 → 30
                            ↑ curr

--------------------------------------------------------

🟢 peek()

    return curr->data

👉 Works because curr always points to top

--------------------------------------------------------

🟢 pop() (IMPORTANT PART)

--------------------------------------------------------

⚠️ What your pop is doing:

    Node* prev = dummy;

    while(prev->next->next != NULL)
        prev = prev->next;

👉 You are finding the SECOND LAST node

--------------------------------------------------------

Then:

    prev->next = curr->next;  // NULL
    curr = prev;

👉 Remove last node

--------------------------------------------------------

🧠 Visualization:

Before:
    dummy → 10 → 20 → 30
                            ↑ curr

After pop:

    dummy → 10 → 20
                        ↑ curr

--------------------------------------------------------

❌ PROBLEM (BIG ONE)

```text
Time Complexity of pop = O(N)

*/


/* class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
}; */

class myStack {

    Node* dummy;
    Node* curr ; 
    int currSize = 0 ; 
    
  public:
    myStack() {
        // Initialize your data members
        dummy = new Node(-1);
        curr = dummy; 
    }

    bool isEmpty() {
        // check if the stack is empty
        if(currSize == 0 )
        {
            return true ; 
        }
        return false; 
    }

    void push(int x) {
        // Adds an element x at the top of the stack
        Node* newNode = new Node(x);
        curr -> next = newNode; 
        curr = newNode; 
        currSize = currSize + 1 ;
    }

    void pop() {
        // Removes the top element of the stack
        if(isEmpty())
        {
            return ; 
        }
        Node* prev = dummy ;
        while(prev -> next -> next != NULL)
            prev = prev -> next; 
        Node* temp = curr; 
        
        prev -> next = curr -> next;  // prev -> next = NULL ; 
        curr = prev ;
        currSize = currSize - 1 ;
        delete(temp);
    }

    int peek() {
        // Returns the top element of the stack
        // If stack is empty, return -1
        if(isEmpty())
        {
            return -1; 
        }
        return curr-> data; 
    }

    int size() {
        // Returns the current size of the stack.
        return currSize;
    }
};

/*
========================================================
🔴 Difference from Your Previous Stack (VERY IMPORTANT SHIFT)
========================================================

You didn’t just “improve” the code…
👉 You COMPLETELY changed the design thinking.

--------------------------------------------------------

🧠 OLD APPROACH (Previous Code)

    dummy → ... → ... → curr (tail)

👉 Stack TOP was at the END (tail)

--------------------------------------------------------

❌ Problem:

- To pop:
    → You had to find "previous node"
    → Required traversal

    while(prev->next->next != NULL)

👉 So:

    pop = O(N) ❌

--------------------------------------------------------

🧠 NEW APPROACH (Current Code)

    curr → ... → ... → NULL

👉 Stack TOP is at the HEAD

--------------------------------------------------------

🔥 This is the key shift:

    OLD: grow RIGHT  → hard to remove
    NEW: grow LEFT   → easy to remove

--------------------------------------------------------

🟢 push() difference

OLD:

    curr->next = newNode
    curr = newNode

👉 Adding at END

--------------------------------------------------------

NEW:

    newNode->next = curr
    curr = newNode

👉 Adding at FRONT

--------------------------------------------------------

🧠 Visual

Push 10, 20, 30

OLD:

    dummy → 10 → 20 → 30 (curr)

NEW:

    curr → 30 → 20 → 10

--------------------------------------------------------

🟢 pop() difference

OLD:

    Traverse whole list to find prev ❌

NEW:

    temp = curr
    curr = curr->next

👉 Direct removal from top

--------------------------------------------------------

🔥 Time Complexity Impact

OLD:

    push → O(1)
    pop  → O(N) ❌

NEW:

    push → O(1)
    pop  → O(1) ✅

--------------------------------------------------------

🟢 peek() difference

OLD:

    return curr->data  (tail)

NEW:

    return curr->data  (head)

👉 Same logic, but now curr is HEAD

--------------------------------------------------------

🟢 Memory / Simplicity

OLD:

    Needed dummy node + traversal logic

NEW:

    No dummy needed
    Cleaner, fewer pointers

--------------------------------------------------------

🧠 Why NEW approach works better

Because singly linked list:

    👉 Can move FORWARD easily
    👉 Cannot move BACKWARD

So:

    Removing from HEAD = easy
    Removing from TAIL = expensive

--------------------------------------------------------

🎯 Core Insight

```text
Stack = LIFO

So always operate at ONE END

Pick the end where operations are O(1)
*/
/* class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
}; */

class myStack {

   
    Node* curr ; 
    int currSize = 0 ; 
    
  public:
    myStack() {
        // Initialize your data members
        
        curr = NULL; 
    }

    bool isEmpty() {
        // check if the stack is empty
        if(currSize == 0 )
        {
            return true ; 
        }
        return false; 
    }

    void push(int x) {
        // Adds an element x at the top of the stack
        Node* newNode = new Node(x);
        newNode -> next = curr; 
        curr = newNode; 
        currSize = currSize + 1 ;
    }

    void pop() {
        // Removes the top element of the stack
        if(isEmpty())
        {
            return ; 
        }
        Node* temp = curr; 
        
        curr = curr -> next; 
        currSize = currSize -1 ; 
        delete(temp);
    }

    int peek() {
        // Returns the top element of the stack
        // If stack is empty, return -1
        if(isEmpty())
        {
            return -1; 
        }
        return curr-> data; 
    }

    int size() {
        // Returns the current size of the stack.
        return currSize;
    }
};