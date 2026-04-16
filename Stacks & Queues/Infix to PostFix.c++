// https://www.geeksforgeeks.org/problems/infix-to-postfix-1587115620/1



/*
🔴 Infix → Postfix Conversion (using Stack)

🧠 Core Idea:
- Operands → directly add to answer
- Operators → use stack based on precedence
- Parentheses → control evaluation order

------------------------------------------------------

📌 Priority:
    ^  → 3 (highest, right associative)
    * / → 2
    + - → 1

------------------------------------------------------

🧠 Flow:

1. If operand (A-Z, a-z, 0-9):
        → add to answer

2. If '(':
        → push to stack

3. If ')':
        → pop until '(' is found
        → discard '('

4. If operator:

        while stack not empty AND
              current priority <= top priority:

            ⚠️ Special case:
                if operator is '^' and equal priority
                → DO NOT pop (right associative)
                → break

            → pop and add to answer

        → push current operator

------------------------------------------------------

🧠 Why special case for '^'?

    ^ is RIGHT associative

    Example:
        a ^ b ^ c
        → a ^ (b ^ c)

    So:
        when equal precedence (^ vs ^)
        → DO NOT pop

------------------------------------------------------

🧠 Final step:

    After traversal:
        pop all remaining operators

------------------------------------------------------

⚡ Complexity:

Time  → O(N)
Space → O(N)

------------------------------------------------------

🎯 Mental Model:

"Operands go to output,
 operators wait in stack until it's safe to use them"

------------------------------------------------------

⚠️ Common Pitfall (you faced this):

- Using continue inside while → infinite loop ❌
- Use break for '^' condition ✅

------------------------------------------------------

🎯 One line:

"Use stack to delay operators until precedence allows"
*/

class Solution {
  public:
    int priority(char c )
    {
        if(c == '^')
        {
            return 3 ;
        }
        else if(c == '*' || c == '/')
        {
            return 2 ; 
        }
        else if(c=='+' || c == '-')
        {
            return 1 ;
        }
        return -1  ;
    }
    string infixToPostfix(string& s) {
        // code here
        stack<char> stk ; 
        int i = 0 ; 
        int n = s.length() ; 
        string ans = "";
        
        while(i< n )
        {
            
            if( (s[i]>='A' && s[i]<='Z') || 
                (s[i]>='a' && s[i]<='z') ||
                (s[i]>='0' && s[i]<='9')
            )
            {
                ans+= s[i];
            }
            
            else if(s[i] == '(')
            {
                stk.push(s[i]); 
            }
            else if(s[i] == ')')
            {
                while( !stk.empty() && stk.top() != '(' )
                {
                  ans =  ans + stk.top();
                  stk.pop(); 
                }
              stk.pop() ; 
            }
            else
            {
                char curr_c = s[i] ; 
                while( !stk.empty() && priority(curr_c) <= priority(stk.top()) )
                {
                    if(priority(curr_c) == priority(stk.top()) && curr_c == '^')
                    {
                        break; 
                    }
                    ans = ans + stk.top() ;
                    stk.pop() ; 
                }
                stk.push(curr_c); 
            }
            i++; 
        }
        
        while( !stk.empty() )
        {
            ans = ans + stk.top() ;
            stk.pop() ; 
        }
        return ans ;
    }
};
