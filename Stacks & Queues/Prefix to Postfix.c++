// https://www.geeksforgeeks.org/problems/prefix-to-postfix-conversion/1

/*
🔴 Prefix → Postfix (Short Notes)

- Traverse RIGHT → LEFT
- Operand → push as string
- Operator → pop 2:
      left  = first pop
      right = second pop
      push: left + right + op

⚠️ Order matters:
    first pop = LEFT
    second pop = RIGHT

🎯 One line:
"Right to left, combine into postfix using stack"
*/

class Solution {
  public:
    string preToPost(string s) {
         
        stack<string> stk ; 
        int n = s.length() ; 
        int i = n-1; 
        while( i >= 0 )
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
                    left = stk.top();
                    stk.pop() ;
                    right  = stk.top() ; 
                    stk.pop() ;
                }
                stk.push(left + right + s[i]) ; 
            }
            i--; 
        }
        return stk.top() ;
    }
};