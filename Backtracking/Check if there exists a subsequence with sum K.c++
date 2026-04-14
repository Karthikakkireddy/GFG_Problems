// https://www.geeksforgeeks.org/problems/check-if-there-exists-a-subsequence-with-sum-k/1


/*
    What my code is doing:

    - I am trying to check if there exists ANY subsequence
      whose sum equals k

    - This is a classic "pick / not pick" recursion

    ------------------------------------------------------

    Parameters meaning:

    - index → current position in array
    - sum   → current accumulated sum

    ------------------------------------------------------

    Logic:

    At each index, I have 2 choices:

    1. Pick the element:
        → sum + arr[index]

    2. Do NOT pick the element:
        → sum remains same

    ------------------------------------------------------

    Early stopping (important):

    - If sum == k
        → return true immediately (no need to explore further)

    - If index == n OR sum > k
        → return false

    ------------------------------------------------------

    Why sum > k check works:

    - Assumes all elements are non-negative
    - If sum already exceeded k → no way to reduce it

    ------------------------------------------------------

    Flow:

        return pick || notPick

    - As soon as one path returns true,
      recursion stops (short-circuit)

    ------------------------------------------------------

    Example:

        arr = [1,2,3], k = 5

        Possible subsequences:
            [2,3] → sum = 5 ✅

        So function returns true

    ------------------------------------------------------

    Time Complexity (TC):

        O(2^N)

    - Each index branches into 2 choices

    ------------------------------------------------------

    Space Complexity (SC):

        O(N)

    - Recursion depth = N

    ------------------------------------------------------

    Important observation:

    - This is a brute-force approach
    - Works fine for small N
    - Can be optimized using DP (subset sum problem)

    👉 DP solution is implemented separately
*/
class Solution {
  public:
    bool checkSubsequenceSumHelper(vector<int>& arr, int k, int sum, int index)
    {
        if(sum == k)
            return true;

        if(index == arr.size() || sum > k)
            return false;

        // pick
        if(checkSubsequenceSumHelper(arr, k, sum + arr[index], index + 1))
            return true;

        // not pick
        if(checkSubsequenceSumHelper(arr, k, sum + 0 , index + 1))
            return true;

        return false; 
    }

    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        return checkSubsequenceSumHelper(arr, k, 0, 0);
    }
};

/*
    Difference from previous version:

    ------------------------------------------------------

    Previous version:

        if(pick) return true;
        if(notPick) return true;
        return false;

    ------------------------------------------------------

    Current version:

        return pick || notPick;

    ------------------------------------------------------

    Key differences:

    1. Cleaner expression

        - Previous version uses explicit if statements
        - Current version directly returns boolean expression

        👉 Less code, easier to read

    ------------------------------------------------------

    2. Same logic, different style

        pick || notPick

        is exactly equivalent to:

            if(pick) return true;
            if(notPick) return true;
            return false;

        👉 No change in behavior

    ------------------------------------------------------

    3. Short-circuit behavior (same in both)

        - If pick == true → notPick is NOT evaluated

        👉 Both versions behave identically here

    ------------------------------------------------------

    4. Less chance of mistakes

        - Previous version can accidentally miss "return false"
        - Current version guarantees return in one line

    ------------------------------------------------------

    Final takeaway:

    ✔ Both are logically same
    ✔ Current version is cleaner and safer
*/
class Solution {
  public:
    bool checkSubsequenceSumHelper(vector<int>& arr, int k, int sum, int index)
    { 
        if(sum == k)
            return true;
        if(index == arr.size() || sum > k)
            return false;

        return checkSubsequenceSumHelper(arr, k, sum+arr[index], index+1) ||
                checkSubsequenceSumHelper(arr, k, sum+0, index+1);
        
        
    }
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        // Code here
        int sum = 0 ; 
        int index = 0;
        return checkSubsequenceSumHelper(arr, k, sum, index);
        
    }
};