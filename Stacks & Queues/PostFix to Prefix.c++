// https://www.geeksforgeeks.org/problems/postfix-to-prefix-conversion/1

/*
🔴 Postfix → Prefix (Short Notes)

- Traverse LEFT → RIGHT
- Operand → push as string
- Operator → pop 2:
      right = first pop
      left  = second pop
      push: op + left + right

⚠️ Order matters:
    first pop = RIGHT
    second pop = LEFT

🎯 One line:
"Left to right, build prefix using stack"
*/
// User function Template for C++

class Solution {
  public:
    string postToPre(string s) {
        // Write your code here
        int i = 0 ; 
        stack<string> stk ; 
        int n = s.length() ; 
        
        while( i < n)
        {
            if((s[i] >= 'A' && s[i] <= 'Z') ||
                (s[i] >= 'a' && s[i] <= 'z') ||
                (s[i] >= '1' && s[i] <= '9')
                )
            {
                stk.push(string(1,s[i])); 
            }
            else
            {
                string left ;
                string right ; 
                if(!stk.empty())
                {
                    right = stk.top();
                    stk.pop() ;
                    left = stk.top() ; 
                    stk.pop() ;
                }
                stk.push( s[i] + left + right ) ; 
            }
            i++; 
        }
        return stk.top() ;
    }
};