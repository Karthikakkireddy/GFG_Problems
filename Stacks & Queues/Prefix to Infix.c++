// https://www.geeksforgeeks.org/problems/prefix-to-infix-conversion/1
/*
🔴 Prefix → Infix (Short Notes)

- Traverse from RIGHT → LEFT
- Operand → push to stack
- Operator → pop 2:
      left = first pop
      right = second pop
      push: "(" + left + op + right + ")"

⚠️ Order matters:
    first pop = LEFT
    second pop = RIGHT

🎯 One line:
"Right to left, combine using stack"
*/
// User function Template for C++

class Solution {
  public:
    string preToInfix(string s) {
        
        
        stack<string> stk;   // stack to store partial expressions
        int n = s.length();
        int i = n -1; 
        while(i >= 0 )
        {
            // If operand → push as string
            if((s[i] >= 'A' && s[i] <= 'Z') ||
               (s[i] >= 'a' && s[i] <= 'z') ||
               (s[i] >= '0' && s[i] <= '9')) 
            {
                stk.push(string(1, s[i]));
            }
            else
            {
                // Operator → needs two operands
                // First pop = left operand
                string exp1 = stk.top(); 
                stk.pop();

                // Second pop = right operand
                string exp2 = stk.top(); 
                stk.pop();

                
                string temp = "(" + exp1 + s[i] + exp2 + ")";

                
                stk.push(temp);
            }
            i--;
        }

        // Final expression will be at top of stack
        return stk.top();
    }
};