// https://www.geeksforgeeks.org/problems/reverse-a-stack/1


/*
    What this code does:

    - Reverses a stack using recursion
    - No extra data structures used

    ------------------------------------------------------

    Core Idea:

    1. Remove all elements from stack (recursively)
    2. Insert each element at the BOTTOM instead of top

    ------------------------------------------------------

    How it works step-by-step:

    reverseStack():

        - Pop top element
        - Recursively reverse remaining stack
        - Insert popped element at bottom

    ------------------------------------------------------

    reverseStackHelper():

        - Inserts an element at the bottom of stack

        Steps:
            - If stack is empty → push element
            - Else:
                → remove top
                → recursively go deeper
                → push removed element back

    ------------------------------------------------------

    Dry Run:

    Stack (top → bottom):
        [3,2,1]

    Step 1:
        pop 3 → reverse [2,1]

    Step 2:
        pop 2 → reverse [1]

    Step 3:
        pop 1 → reverse []

    Now stack is empty

    Insert back:

        insert 1 → [1]
        insert 2 → goes below 1 → [1,2]
        insert 3 → goes below → [1,2,3]

    Final reversed stack:
        [1,2,3]

    ------------------------------------------------------

    Time Complexity:

        O(N^2)

    - For each element, we traverse stack again to insert at bottom

    ------------------------------------------------------

    Space Complexity:

        O(N)

    - Recursion stack

    ------------------------------------------------------

    Key Insight:

    👉 We are not "reversing directly"
    👉 We are "rebuilding stack from bottom"
*/
class Solution {
  public:
  
    void reverseStackHelper(stack<int> &st, int topEle)
    {
        if(st.empty())
        {
            st.push(topEle);
        }
        else
        {
            int temp = st.top();
            st.pop();
            reverseStackHelper(st, topEle);
            st.push(temp);
        }
        
    }
    void reverseStack(stack<int> &st) {
        // code here
        if(st.empty()) 
            return ;
        else
        {
            int topEle = st.top();
            st.pop();
            reverseStack(st);
            reverseStackHelper(st, topEle);
        }
       
        
    }
};