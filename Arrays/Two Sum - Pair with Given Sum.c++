// https://www.geeksforgeeks.org/problems/key-pair5616/1

/*
🔴 Two Sum (Brute Force)

🧠 Idea:
- Check every possible pair in the array.
- If any pair's sum equals target, return true.
- If no such pair exists, return false.

🧠 Example:
arr = [2,7,11,15]
target = 9

2 + 7 = 9 ✅

Answer = true

🧠 Why j starts from i+1?
- Avoid using the same element twice.
- Avoid checking duplicate pairs.

Example:
(2,7) is checked
(7,2) need not be checked again.

⏱️ TC: O(N²)
📦 SC: O(1)

🎯 One line:
"Check every possible pair and see if their sum equals the target."
*/
class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        for(int i=0 ; i< n -1 ; i++)
        {
            for(int j=i+1; j < n ; j++)
            {
                int sum = arr[i] + arr[j];
                
                if(sum == target)
                    return true;
            }
        }
        
        return false;
    }
    
    
};




/*
🔴 Two Sum (Hash Set)

🧠 Idea:
- For every element x, compute the required value:

      target - x

- If the required value has already been seen,
  then a valid pair exists.
- Otherwise store x in the set and continue.

🧠 Example:
arr = [2,7,11,15]
target = 9

2:
    need 7
    not found
    insert 2

7:
    need 2
    found ✅

Answer = true

🧠 Why check before inserting?

Suppose:

arr = [3]
target = 6

If we insert first:

    insert 3
    look for (6 - 3) = 3

We find the same element and incorrectly return true.

By checking first and inserting later,
the set contains only previously seen elements,
so we always form a pair using two different indices.

⏱️ TC: O(N)
📦 SC: O(N)

🎯 One line:
"For each element, look for its complement among previously seen elements."
*/
class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        // code here
       unordered_set<int> st ;
        int n = arr.size();
       
       
       for(int i=0 ; i< n ; i++)
       {
           
           if(st.find(target - arr[i]) != st.end())
           {
               return true;
           }
           st.insert(arr[i]);
       }
       return false;
    }
    
    
};


/*
🔴 Two Sum (Sorting + Two Pointers)

🧠 Idea:
- Sort the array.
- Keep one pointer at the smallest element (left).
- Keep another pointer at the largest element (right).
- Calculate their sum and adjust pointers accordingly.

🧠 Example:
arr = [2,7,11,15]
target = 9

left = 2
right = 15

2 + 15 = 17 > 9
→ move right

2 + 11 = 13 > 9
→ move right

2 + 7 = 9 ✅

Answer = true

🧠 Why move left when sum < target?
- Array is sorted.
- To increase the sum, we need a larger value.
- Moving left forward gives a larger element.

🧠 Why move right when sum > target?
- Array is sorted.
- To decrease the sum, we need a smaller value.
- Moving right backward gives a smaller element.

⏱️ TC: O(N log N) + O(N)
      = O(N log N)

📦 SC: O(1)

🎯 One line:
"Sort the array and use two pointers to adjust the sum toward the target."
*/
class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        // code here
       sort(arr.begin(), arr.end());
       
       int left = 0, right = arr.size()-1 ;
       while(left < right)
       {
           int sum = arr[left] + arr[right];
           if(sum < target)
           {
               left++;
           }
           else if(sum > target)
           {
               right--;
           }
           else
           {
               return true;
           }
       }
       return false;
    }
    
    
};