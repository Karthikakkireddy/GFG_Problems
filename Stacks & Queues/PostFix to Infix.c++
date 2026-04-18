// https://www.geeksforgeeks.org/problems/postfix-to-infix-conversion/1

class Solution {
  public:
    string postToInfix(string &s) {
        int i = 0; 
        stack<string> stk;   // stack to store partial expressions
        int n = s.length();

        while(i < n)
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
                // First pop = right operand
                string exp1 = stk.top(); 
                stk.pop();

                // Second pop = left operand
                string exp2 = stk.top(); 
                stk.pop();

                // Form new expression: (left op right)
                string temp = "(" + exp2 + s[i] + exp1 + ")";

                // Push back to stack as a single expression
                stk.push(temp);
            }
            i++;
        }

        // Final expression will be at top of stack
        return stk.top();
    }
};