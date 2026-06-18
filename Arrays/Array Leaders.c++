// https://www.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1

/*
🔴 Leaders in an Array

🧠 Idea:
- Traverse from right to left.
- The last element is always a leader.
- An element is a leader if it is greater than or equal to
  every element on its right.
- Keep track of the largest leader seen so far using v.back().

🧠 Example:
arr = [16,17,4,3,5,2]

Start:
v = [2]

5 >= 2  → leader → v = [2,5]
3 >= 5  → no
4 >= 5  → no
17 >= 5 → leader → v = [2,5,17]
16 >= 17 → no

Reverse:

[17,5,2]

Answer = [17,5,2]

🧠 Why compare with v.back()?
- v.back() is the largest element encountered so far
  while moving from right to left.
- If current element is >= v.back(),
  it is a leader.

⏱️ TC: O(N)
📦 SC: O(N)

🎯 One line:
"Traverse from right to left and keep elements that are greater than or equal to all elements seen so far."
*/


class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
        // code here
        vector<int> v;
        v.push_back(arr[arr.size()-1]);
        
        for(int i= arr.size()-2; i>=0; i--)
        {
            if(v.back() <= arr[i])
            {
                v.push_back(arr[i]);
            }
        }
        
        reverse(v.begin(), v.end());
        
        return v;
    }
};



// Same approach different way


class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
        // code here
        int maxElementTillNow = INT_MIN; 
        int n = arr.size();
        vector<int> v;
        for(int i= n-1 ; i>= 0 ; i--)
        {
            maxElementTillNow = max(maxElementTillNow, arr[i]);
            if(maxElementTillNow == arr[i])
                v.emplace_back(maxElementTillNow);
        }
        
        reverse(v.begin(), v.end());
        return v;
    }
};