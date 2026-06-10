// https://www.geeksforgeeks.org/problems/missing-number-in-array1416/1



/*
🔴 Missing Number (Brute Force)

🧠 Idea:

- Check every number from 1 to n.

- For each number:
    Search the entire array.

- If the number is not found,
  then that number is missing.

------------------------------------------------------

Flow:

For i = 1 to n:

    Search i in the array

    If not found:
        return i

------------------------------------------------------

🧠 Example:

arr = [1,2,4,5]

Check 1 → found
Check 2 → found
Check 3 → not found

Answer = 3

------------------------------------------------------

⏱️ TC:

Outer loop  → O(N)
Inner loop  → O(N)

Total:
    O(N²)

------------------------------------------------------

📦 SC:

    O(1)

------------------------------------------------------

🎯 One line:

"For every number from 1 to n, scan the array to see if it exists."
*/
class Solution {
  public:
    int missingNum(vector<int>& arr) {
        // code here
        int missingNumber; 
        
        for(int i=1; i<= arr.size()+1; i++)
        {
            bool flag = false;
            for(int j=0 ; j < arr.size(); j++)
            {
                if(arr[j] == i)
                {
                    flag = true; 
                    break;
                }
            }
            
            if(flag == false)
            {
                missingNumber = i; 
                break;
            }
        }
        
        return missingNumber;
    }
};

/*

Better approach 

🔴 Missing Number (Hashing / Frequency Array)

🧠 Idea:

- Create an auxiliary array of size n+1.

- Use indices as numbers.

- Mark every number present in arr.

------------------------------------------------------

Flow:

1. Create frequency array initialized with 0.

2. For every element x in arr:

       v[x] = 1

3. Traverse from 1 to n.

4. First index whose value is 0
   is the missing number.

------------------------------------------------------

🧠 Example:

arr = [1,2,4,5]

Initially:

    v = [0,0,0,0,0,0]

Mark present numbers:

    v[1] = 1
    v[2] = 1
    v[4] = 1
    v[5] = 1

Result:

    [0,1,1,0,1,1]

Check from 1 to n:

    1 → present
    2 → present
    3 → missing

Answer = 3

------------------------------------------------------

⏱️ TC:

    O(N)

------------------------------------------------------

📦 SC:

    O(N)

------------------------------------------------------

🎯 One line:

"Mark all present numbers and find the first unmarked one."
*/
class Solution {
  public:
    int missingNum(vector<int>& arr) {
        // code here
        int vectorSize = arr.size(); 
        int n = vectorSize + 1; 
        vector<int> v(n+1);
        
        for(int i=0 ; i< vectorSize ; i++)
        {
            v[arr[i]] = 1 ;
        }
        
        for(int i=1; i<=n; i++)
        {
            if(v[i] == 0 )
                return i;
        }
        
        return -1;
    }
};

/*
🔴 Missing Number (Sum Formula)

🧠 Idea:

- Numbers should be from:
      1 to n

- Find:
      Expected Sum of 1...n

- Find:
      Actual Sum of array elements

- Difference between them is the missing number.

------------------------------------------------------

Formula:

      n * (n + 1)
sum = ------------
            2

------------------------------------------------------

⚠️ Important:

Use long long for sums.

Reason:

    n * (n + 1)

and

    vectorSum += x

may exceed INT_MAX during calculation.

------------------------------------------------------

⏱️ TC: O(N)

📦 SC: O(1)

------------------------------------------------------

🎯 One line:

"Missing Number = Expected Sum − Actual Sum"
*/
class Solution {
  public:
    int missingNum(vector<int>& arr) {
        // code here
        int sizeVector = arr.size(); 
        int n = sizeVector + 1;
        
        long long  sum = (1LL * n * (n + 1 ) ) / 2;
        
        long long vectorSum = 0;
        
        for(auto x : arr)
        {
            vectorSum += x; 
        }
        
        return sum - vectorSum;
    }
};

/*
🔴 Missing Number (XOR Approach)

🧠 Idea:

- XOR all numbers from 1 to n
      → xor1

- XOR all elements present in array
      → xor2

- Missing number will remain after:

      xor1 ^ xor2

------------------------------------------------------

🧠 Why does it work?

XOR Properties:

    a ^ a = 0
    a ^ 0 = a

So every number that appears in both
groups cancels out.

Only the missing number remains.

------------------------------------------------------

🧠 Example:

arr = [1,2,4,5]

n = 5

xor1:

    1 ^ 2 ^ 3 ^ 4 ^ 5

xor2:

    1 ^ 2 ^ 4 ^ 5

Result:

    xor1 ^ xor2

    = (1^1) ^ (2^2) ^ 3 ^ (4^4) ^ (5^5)

    = 3

------------------------------------------------------

⏱️ TC:

    O(N)

------------------------------------------------------

📦 SC:

    O(1)

------------------------------------------------------

🎯 One line:

"Equal numbers cancel each other in XOR, leaving only the missing number."
*/
class Solution {
  public:
    int missingNum(vector<int>& arr) {
        // code here
        int xor1 =0 , xor2 = 0;
        int n = arr.size() + 1; 
        
        for(int i=1 ; i<=n ;i++)
        {
            xor1 ^= i;
        }
        
        for(int i=0; i< arr.size() ; i++)
        {
            xor2 ^= arr[i];
        }
        
        return xor1 ^ xor2;
    }
};