// https://www.geeksforgeeks.org/problems/implement-queue-using-linked-list/1

/*
========================================================
🔴 Queue using Linked List (with Dummy Node)
========================================================

🧠 Idea:

- We are implementing a queue (FIFO)
- Using a singly linked list
- Using a dummy node to simplify edge cases

--------------------------------------------------------

📦 Structure

    dummy → first REAL element (front)
    back  → last element (rear)

Example:

    dummy → 10 → 20 → 30
                             ↑
                           back

👉 IMPORTANT:
    dummy itself is NOT part of queue
    dummy->next is ALWAYS the FRONT

--------------------------------------------------------

🟢 Why dummy node?

Without dummy:
    → Need separate front pointer
    → Many edge cases (empty, first insert, etc.)

With dummy:
    → dummy->next always points to front
    → uniform logic for insert/delete

--------------------------------------------------------

🟢 Constructor

    dummy = new Node(-1);
    back = dummy;
    currSize = 0;

👉 Empty queue:

    dummy → NULL
    back = dummy

--------------------------------------------------------

🟢 isEmpty()

    currSize == 0

👉 Clean and reliable

--------------------------------------------------------

🟢 enqueue(x)

Steps:

1. Create new node
2. Attach it after back
3. Move back pointer
4. Increase size

--------------------------------------------------------

Flow:

Before:
    dummy → 10 → 20
                       ↑ back

enqueue(30):

    back->next = newNode
    back = newNode

After:
    dummy → 10 → 20 → 30
                             ↑ back

--------------------------------------------------------

🧠 Key idea:

    Always insert at BACK (tail)

--------------------------------------------------------

🟢 dequeue()

Steps:

1. If empty → do nothing

--------------------------------------------------------

2. Special case: only ONE element

    if(dummy->next == back)

👉 Means:
    Only one node exists

So after removal:
    queue becomes empty

    back = dummy

--------------------------------------------------------

3. Remove front node

    temp = dummy->next
    dummy->next = temp->next

👉 This removes FIRST element

--------------------------------------------------------

4. Delete node and reduce size

--------------------------------------------------------

🧠 Visualization

Before:
    dummy → 10 → 20 → 30
             ↑ front

After dequeue:

    dummy → 20 → 30

--------------------------------------------------------

🧠 Key insight:

    We NEVER move dummy
    We only adjust dummy->next

--------------------------------------------------------

🟢 getFront()

    return dummy->next->data

👉 Because:
    dummy->next is ALWAYS front

--------------------------------------------------------

🟢 size()

    return currSize

--------------------------------------------------------

🔥 Why this design is clean

✔ No separate front pointer needed
✔ No complicated edge cases
✔ All operations are O(1)

--------------------------------------------------------

⚠️ Important edge case handled

    if(dummy->next == back)

👉 Without this:

    back would still point to deleted node ❌

--------------------------------------------------------

🧠 Mental Model

Think like this:

    dummy = fixed anchor
    front = dummy->next
    back  = last node

--------------------------------------------------------

🎯 One-line takeaway

```text
Queue + Linked List → 
Insert at back, remove from dummy->next
*/

class Node {
  public:
    int data;
    Node* next;

    Node(int new_data) {
        data = new_data;
        next = nullptr;
    }
};

class myQueue {
    
    Node* dummy ;
    Node* back ;
    
    int currSize ;
    
  public:
    myQueue() {
        // Initialize your data members
        dummy = new Node(-1);
        back = dummy ;
        currSize = 0 ; 
    }

    bool isEmpty() {
        // check if the queue is empty
        if(currSize == 0 )
        {
            return true;
        }
        return false;
    }

    void enqueue(int x) {
        // Adds an element x at the rear of the queue
        Node* newNode = new Node(x); 
        back -> next = newNode; 
        back = newNode; 
        currSize = currSize + 1; 
        
        
        
    }

    void dequeue() {
        // Removes the front element of the queue
        if(isEmpty())
        {
            return ;
        }
        if(dummy -> next == back )
        {
            back = dummy ; 
        }
        
        
        Node* temp = dummy -> next ; 
        dummy -> next = temp -> next; 
        
        delete (temp);
        currSize = currSize -1 ; 
        
    }

    int getFront() {
        // Returns the front element of the queue
        // If queue is empty, return -1
        if(isEmpty())
        {
            return -1;
        }
        return dummy -> next -> data ; 
    }

    int size() {
        // Returns the current size of the queue.
        return currSize; 
    }
};

/*
🔴 Queue (LL without dummy) – Quick Notes

- front → where we REMOVE
- back  → where we INSERT

--------------------------------------------------

enqueue(x):

1. Create new node
2. If queue not empty:
       back->next = newNode
3. Move back:
       back = newNode
4. If first element:
       front = back

👉 Key:
    First insert → set BOTH front & back

--------------------------------------------------

dequeue():

1. If empty → return

2. Store front

3. If only one node:
       front = NULL
       back = NULL
   else:
       front = front->next

4. delete old node

👉 Key:
    Last deletion → reset BOTH pointers

--------------------------------------------------

getFront():
    return front->data

--------------------------------------------------

🧠 Mental Model:

    push → back grows →
    pop  → front moves →

--------------------------------------------------

⚡ Difference from dummy version:

- No dummy → more edge cases
- Need to handle:
    ✔ first insert
    ✔ last delete

--------------------------------------------------

🎯 One line:

    "Queue = insert at back, remove from front"
*/
class Node {
  public:
    int data;
    Node* next;

    Node(int new_data) {
        data = new_data;
        next = nullptr;
    }
};



class myQueue {
    
    Node* front ;
    Node* back ;
    
    int currSize ;
    
  public:
    myQueue() {
        // Initialize your data members
        front = NULL ;
        back = NULL ;
        currSize = 0 ; 
    }

    bool isEmpty() {
        // check if the queue is empty
        if(currSize == 0 )
        {
            return true;
        }
        return false;
    }

    void enqueue(int x) {
        // Adds an element x at the rear of the queue
        Node* newNode = new Node(x); 
        
        if(back != NULL)
        {
            back -> next = newNode; 
        }
        back = newNode ; 
        
        currSize = currSize + 1; 
        
        if(front == NULL)
        {
            front = back ; 
        }
        
        
        
    }

    void dequeue() {
        // Removes the front element of the queue
        if(isEmpty())
        {
            return ;
        }
       
        
        
        Node* temp = front ; 
        if(front -> next == NULL) // One node remaining
        {
            back = NULL; 
            front = NULL;
        }
        else // More than one node are present
        {
            front = front -> next ;
        }
       
        
        delete (temp);
        currSize = currSize -1 ; 
        
    }

    int getFront() {
        // Returns the front element of the queue
        // If queue is empty, return -1
        if(isEmpty())
        {
            return -1;
        }
        return front -> data ; 
    }

    int size() {
        // Returns the current size of the queue.
        return currSize; 
    }
};
