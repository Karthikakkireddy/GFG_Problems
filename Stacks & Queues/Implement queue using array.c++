https://www.geeksforgeeks.org/problems/implement-queue-using-array/1

/*
========================================================
🔴 Queue using Circular Array (VERY IMPORTANT CONCEPT)
========================================================

🧠 Goal:
Implement a queue using an array efficiently
→ Avoid wasting space after dequeue
→ Use circular behavior

--------------------------------------------------------

📦 Core Idea: Circular Queue

Instead of:
    [ ][ ][ ][ ][ ]

We reuse space like a circle:

    index: 0 1 2 3 4
            ↑     ↑
           end   start

👉 After reaching end, we wrap around using:

    (index + 1) % size

--------------------------------------------------------

🧠 Variables Meaning

    vector<int> v       → storage
    int start           → index of FRONT element
    int end             → index of REAR element
    int currentSize     → number of elements in queue

--------------------------------------------------------

🔴 INITIAL STATE

    start = -1
    end   = -1
    size  = 0

👉 Means:
    Queue is EMPTY

--------------------------------------------------------

🟡 isEmpty()

    if(start == -1 & end == -1)

⚠️ Small bug:
    Should be:
        (start == -1 && end == -1)

👉 Current code uses bitwise &, works but NOT correct practice

--------------------------------------------------------

🟡 isFull()

    if(currentSize == v.size())

👉 Because we are using circular array,
    full condition is tracked by size

--------------------------------------------------------

🟢 enqueue(x)

--------------------------------------------------------

Step 1: Check if queue is empty

    if(isEmpty())
        start = start + 1;   → start becomes 0

👉 First element initialization

--------------------------------------------------------

Step 2: Move end

    end = (end + 1) % v.size();

👉 This is the MOST IMPORTANT LINE

Example:
    size = 5
    end = 4 → (4+1)%5 = 0 → wraps around

--------------------------------------------------------

Step 3: Insert

    v[end] = x;

--------------------------------------------------------

Step 4: Increase size

    currentSize++

--------------------------------------------------------

🧠 Visualization

Before:
    start = 0, end = 2

After enqueue:
    end moves → insert → size++

--------------------------------------------------------

🟢 dequeue()

--------------------------------------------------------

Step 1: If empty → do nothing

--------------------------------------------------------

Step 2: If only ONE element

    if(start == end)

👉 Means:
    only one element present

So reset everything:

    start = -1
    end   = -1
    currentSize = 0

--------------------------------------------------------

Step 3: Move start

    start = (start + 1) % v.size();

👉 Removes front logically

--------------------------------------------------------

Step 4: Decrease size

    currentSize--

--------------------------------------------------------

🧠 Key insight:

    We DO NOT delete element physically
    We just move start pointer

--------------------------------------------------------

🟢 getFront()

    return v[start]

👉 Front = start

--------------------------------------------------------

🟢 getRear()

    return v[end]

👉 Rear = end

--------------------------------------------------------

🔥 WHY THIS DESIGN WORKS

--------------------------------------------------------

1. Circular movement:

    (index + 1) % size

    → reuses space
    → avoids shifting elements

--------------------------------------------------------

2. currentSize is critical

👉 Without this, we cannot distinguish:

    full vs empty

Because:
    start == end can mean BOTH

--------------------------------------------------------

3. Special reset case:

    if(start == end)

👉 Required to reset queue to EMPTY state

--------------------------------------------------------

⚠️ Common Mistakes (you avoided most)

❌ Forget modulo → array overflow
❌ Not handling single element case
❌ Confusing full vs empty
❌ Not tracking size

--------------------------------------------------------

🧠 Mental Model (VERY IMPORTANT)

Think of queue like a clock:

    0 → 1 → 2 → 3 → 4 → back to 0

Pointers move, data stays.

--------------------------------------------------------

🎯 One-line summary:

    start → where to REMOVE
    end   → where to INSERT
    size  → how full queue is

--------------------------------------------------------

💡 If you revisit after 1 year:

Just remember:

    "Circular + modulo + size tracking"

Everything else will fall into place.

========================================================
*/
class myQueue {

  public:
    
    int start = -1 ;
    int end = -1; 
    vector<int> v;
    int currentSize = 0 ; 
    myQueue(int n) {
        // Define Data Structures
        v.resize(n);
        
    }

    bool isEmpty() {
        // check if the queue is empty
        if(start == -1 && end == -1)
        {
            return true; 
        }
        return false;
    }

    bool isFull() {
        // check if the queue is full
        if(currentSize == v.size())
        {
            return true; 
        }
        return false;
    }

    void enqueue(int x) {
        // Adds an element x at the rear of the queue.
        if(isEmpty())
        {
            start = start +1;
        }
        end = (end + 1) % v.size() ;
        
        v[end] = x;
        currentSize = currentSize + 1; 
        
    }

    void dequeue() {
        // Removes the front element of the queue.
        if(isEmpty())
        {
            // cout << "Can't be dequed";
            return ;
        }
        if(start == end)
        {
            currentSize = 0 ; 
            start = -1; 
            end = -1;
            return ;
        }
        
        start = (start + 1) % v.size() ; 
        currentSize = currentSize -1; 
        
    }

    int getFront() {
        // Returns the front element of the queue.
        if(isEmpty())
        {
            // cout << "Queue is empty";
            return -1;
        }
        return v[start];
    }

    int getRear() {
        // Return the last element of queue
        if(isEmpty())
        {
            // cout << "Queue is empty";
            return -1;
        }
        return v[end];
    }
};