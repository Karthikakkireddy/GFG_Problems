// https://www.geeksforgeeks.org/problems/consecutive-1s-not-allowed1912/1


//  ------------------------------------------------------

//     ⚠️ Important Note (Optimization):

//     - This is NOT an optimal solution

//     - Time Complexity:
//         O(2^N) → exponential recursion

//     - Reason:
//         Same states (index, previous element) are recomputed multiple times

//     ------------------------------------------------------

//     ✅ Optimal approach:

//     - This problem follows a DP pattern (similar to Fibonacci)
//     - Can be solved in O(N) or even O(log N)

//     👉 DP solution is implemented separately in another folder

//     ------------------------------------------------------
/*
    What my code is doing:

    - I am generating all binary strings of length n
    - With the constraint:
        → No two consecutive 1s

    ------------------------------------------------------

    Parameters meaning:

    - index → current position in string
    - currentEle → previous element placed (0 or 1)

    ------------------------------------------------------

    Logic:

    At each index:

    1. Always place '0'
        → because 0 can come after both 0 and 1

        result += helper(index+1, 0)

    2. Place '1' ONLY if previous was 0

        if(currentEle == 0)
            result += helper(index+1, 1)

    ------------------------------------------------------

    Base case:

        if(index == n)
            return 1

    👉 Means:
        We formed a valid string of length n

    ------------------------------------------------------

    What this effectively does:

    - Explores all valid binary strings
    - Avoids invalid ones (like "11") by restricting choices

    ------------------------------------------------------

    Example (n = 3):

        Possible valid strings:
            000
            001
            010
            100
            101

        Total = 5

    ------------------------------------------------------

    Important observation:

    - This is a brute-force generation approach
    - It builds all valid strings recursively
*/
class Solution {
  public:
    int countStringsHelper(int n , int index, int currentEle)
    {
        if(n == index)
        {
            return 1;
        }
        int result = 0 ; 
        
        result = result + countStringsHelper(n, index+1, 0);
        if(currentEle == 0)
        {
            result = result + countStringsHelper(n, index+1, 1);
        }
        
        return result;
    }
    int countStrings(int n) {
        // code here
        int index = 0 ; 
        int currentEle = 0;
        
        return countStringsHelper(n, index, currentEle);
        
    }
};