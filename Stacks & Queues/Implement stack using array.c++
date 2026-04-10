https://www.geeksforgeeks.org/problems/implement-stack-using-array/1


class myStack {
  public:
    int currIndex = 0; 
    vector<int> v;
    myStack(int n) {
        // Define Data Structures
        v.resize(n);
        
    }

    bool isEmpty() {
        // check if the stack is empty
        if(currIndex == 0)
        {
            return true ;
        }
        return false;
    }

    bool isFull() {
        // check if the stack is full
        if(currIndex == v.size())
            return true; 
        return false;
        
    }

    void push(int x) {
        // inserts x at the top of the stack
        v[currIndex++] = x;
        
        
    }

    void pop() {
        // removes an element from the top of the stack
        if(currIndex == 0 )
        {
            return;
        }
        v[--currIndex] = 0;
    }

    int peek() {
        // Returns the top element of the stack
        if(currIndex == 0)
            return -1;
        return v[currIndex -1 ];
    }
};









class myStack {
  public:
    int currIndex = -1; 
    vector<int> v;
    myStack(int n) {
        // Define Data Structures
        v.resize(n);
        
    }

    bool isEmpty() {
        // check if the stack is empty
        if(currIndex == -1)
        {
            return true ;
        }
        return false;
    }

    bool isFull() {
        // check if the stack is full
        if(currIndex+1 == v.size())
            return true; 
        return false;
        
    }

    void push(int x) {
        // inserts x at the top of the stack
        v[++currIndex] = x;
        
        
    }

    void pop() {
        // removes an element from the top of the stack
        if(currIndex != -1)
            --currIndex; 
        return ;
       
    }

    int peek() {
        // Returns the top element of the stack
        if(currIndex == -1)
            return -1;
        return v[currIndex];
    }
};


/*
========================================================
🔴 Difference Between Two Stack Implementations
========================================================

Both implementations use:
    - vector<int> v → underlying storage
    - currIndex → tracks top of stack

But they differ in HOW they interpret currIndex

--------------------------------------------------------

🟡 VERSION 1 (currIndex = 0)

    int currIndex = 0;

--------------------------------------------------------

🧠 Meaning:

    currIndex = "next free position"
    
    Stack looks like:
    
        [10][20][30][_][_]
                 ↑
            currIndex = 3

👉 Top element is at:
        currIndex - 1

--------------------------------------------------------

⚙️ Behavior:

push:
    v[currIndex++] = x;

pop:
    --currIndex;

peek:
    v[currIndex - 1]

--------------------------------------------------------

⚠️ Key Observations:

❌ Slightly unintuitive
    → currIndex does NOT point to actual top

❌ Always need "-1" adjustment for peek

❌ pop() modifies array (sets to 0) → unnecessary

--------------------------------------------------------

🟢 VERSION 2 (currIndex = -1)

    int currIndex = -1;

--------------------------------------------------------

🧠 Meaning:

    currIndex = "index of top element"

    Stack looks like:

        [10][20][30][_][_]
                 ↑
            currIndex = 2

👉 Top element is directly:
        v[currIndex]

--------------------------------------------------------

⚙️ Behavior:

push:
    v[++currIndex] = x;

pop:
    --currIndex;

peek:
    v[currIndex]

--------------------------------------------------------

⚡ Key Observations:

✔ More intuitive
    → currIndex directly represents top

✔ No need for "-1" adjustment

✔ Cleaner logic in push/pop/peek

✔ pop() does NOT modify array → correct behavior

--------------------------------------------------------

🔥 isEmpty() Comparison

Version 1:
    currIndex == 0

Version 2:
    currIndex == -1

👉 Version 2 clearly expresses:
    "no elements present"

--------------------------------------------------------

🔥 isFull() Comparison

Version 1:
    currIndex == v.size()

Version 2:
    currIndex + 1 == v.size()

👉 Both are correct based on interpretation

--------------------------------------------------------

🎯 Final Verdict

Version 2 is BETTER because:

✔ Cleaner mental model
✔ Direct mapping to "top"
✔ Less off-by-one confusion
✔ Matches standard stack implementation

--------------------------------------------------------

🧠 One-line takeaway:

Version 1 → "pointer to next slot"
Version 2 → "pointer to current top" ✅ preferred

========================================================
*/