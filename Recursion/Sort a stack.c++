// https://www.geeksforgeeks.org/problems/sort-a-stack/1


/*
    What this code does:

    - Sorts a stack using recursion
    - No extra data structures used

    ------------------------------------------------------

    Core Idea:

    1. Remove all elements (recursively)
    2. Insert each element back in sorted order

    👉 Similar to insertion sort logic

    ------------------------------------------------------

    How it works:

    sortStack():

        - Pop top element
        - Recursively sort remaining stack
        - Insert popped element in correct position

    ------------------------------------------------------

    sortStackHelper():

        - Inserts element into already sorted stack

        Cases:

        1. If stack is empty:
            → push element

        2. If element >= top:
            → push directly (correct position)

        3. Else:
            → remove top
            → recursively find correct position
            → push removed element back

    ------------------------------------------------------

    Dry Run:

    Stack (top → bottom):
        [3,1,2]

    Step 1:
        pop 3 → sort [1,2]

    Step 2:
        pop 1 → sort [2]

    Step 3:
        pop 2 → sort []

    Insert back:

        insert 2 → [2]
        insert 1 → goes below → [1,2]
        insert 3 → goes on top → [1,2,3]

    ------------------------------------------------------

    Time Complexity:

        O(N^2)

    - For each element, we may traverse stack again

    ------------------------------------------------------

    Space Complexity:

        O(N)

    - Recursion stack

    ------------------------------------------------------

    Key Insight:

    👉 First recursion removes everything
    👉 Second recursion inserts in sorted order

    👉 Stack is rebuilt in sorted form
*/
class Solution {
  public:
  
    void sortStackHelper(stack<int> &st, int topElement)
    {
        
        if(st.empty())
        {
            st.push(topElement);
            return ;
        }
        
        
        if(topElement >= st.top())
        {
            st.push(topElement);
            return ;
        }
        else
        {
            int temp = st.top();
            st.pop();
            sortStackHelper(st, topElement);
            st.push(temp);
        } 

    }
    void sortStack(stack<int> &st) {
        // code here
        if(st.empty())
        {
            return ;
        }
        else
        {
            
           
            int topElement = st.top(); 
            st.pop();
            sortStack(st);
            sortStackHelper(st, topElement);
        }
        
    }
};
