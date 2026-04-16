// https://www.geeksforgeeks.org/problems/infix-to-prefix-notation/1


/*
🔴 Infix → Prefix Conversion (using reverse + postfix idea)

🧠 Core Trick:

Instead of writing a new logic,
we REUSE infix→postfix logic with small changes

------------------------------------------------------

📌 Steps:

1. Reverse the string
2. Swap brackets:
       '(' ↔ ')'
3. Apply infix → postfix logic
4. Reverse final answer → gives prefix

------------------------------------------------------

🧠 What your code is doing:

✔ Step 1:
    reverse(s)

✔ Step 2 (handled implicitly):
    - '(' treated like ')'
    - ')' treated like '('

✔ Step 3:
    Apply postfix logic using stack

✔ Step 4:
    reverse(ans)

------------------------------------------------------

🧠 Operator handling:

Two cases:

1. For '^' (RIGHT associative):
       while(priority(curr) <= priority(top))

2. For others:
       while(priority(curr) < priority(top))

👉 This is opposite of postfix logic due to reversal

------------------------------------------------------

🧠 Why different condition?

Because reversing changes associativity behavior

Example:

    a ^ b ^ c

Original:
    a ^ (b ^ c)

After reverse:
    c ^ b ^ a

👉 Now behaves like LEFT associative

So condition changes

------------------------------------------------------

🧠 Parentheses handling:

After reversing:

    '(' becomes ')'
    ')' becomes '('

So:

    if ')': push
    if '(': pop until ')'

------------------------------------------------------

⚡ Complexity:

Time  → O(N)
Space → O(N)

------------------------------------------------------

🎯 Mental Model:

"Reverse → solve like postfix → reverse answer"

------------------------------------------------------

⚠️ Subtle thing:

You correctly handled '^' differently
👉 This is where most people mess up

------------------------------------------------------

🎯 One line:

"Prefix = reverse(infix) → postfix → reverse result"
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
    string infixToPrefix(string &s) {
        // code here
        reverse(s.begin() , s.end());
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
            
            else if(s[i] == ')')
            {
                stk.push(s[i]); 
            }
            else if(s[i] == '(')
            {
                while( !stk.empty() && stk.top() != ')' )
                {
                  ans =  ans + stk.top();
                  stk.pop(); 
                }
              stk.pop() ; 
            }
            else
            {
                if(s[i] == '^')
                {
                    while(!stk.empty() && priority(s[i]) <= priority(stk.top()))
                    {
                        ans += stk.top() ; 
                        stk.pop() ; 
                    }
                }
                else
                {
                    while(!stk.empty() && priority(s[i]) < priority(stk.top()))
                    {
                        ans += stk.top() ; 
                        stk.pop() ; 
                    }
                }
                stk.push(s[i]);
            }
            i++; 
        }
        
        while( !stk.empty() )
        {
            ans = ans + stk.top() ;
            stk.pop() ; 
        }
        reverse(s.begin() , s.end());
        reverse(ans.begin() , ans.end());
        return ans ;
    }
};
