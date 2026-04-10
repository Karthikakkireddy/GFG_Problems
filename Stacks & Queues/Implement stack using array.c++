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