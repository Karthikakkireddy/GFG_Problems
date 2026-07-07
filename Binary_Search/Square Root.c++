// https://www.geeksforgeeks.org/problems/square-root/1


/*
    🔴 Brute Force

    🧠 Idea:
        - Start checking numbers from 1 onwards.
        - Compute the square of each number.
        - Continue until the square becomes greater than n.
        - The last number whose square is less than or
          equal to n is the floor square root.

    -------------------------------------------------------

    Why This Works

        - The floor square root is the largest integer
          whose square does not exceed n.
        - As soon as the square becomes greater than n,
          no larger number can be the answer.

    -------------------------------------------------------

    ⏱️ Time Complexity

        In the worst case:
            Iterate from 1 to √N

        Total:
            O(√N)

    -------------------------------------------------------

    📦 Space Complexity

        Extra Variables:
            O(1)

        Total Auxiliary Space:
            O(1)

    -------------------------------------------------------

    ⚠️ Note

        - For large values of n,

              (i + 1) * (i + 1)

          can overflow an int.

        - Use long long while computing the square.

    -------------------------------------------------------

    🎯 One Line

        "Iterate until the square exceeds n; the previous number is the floor square root."
*/
class Solution {
  public:
    int floorSqrt(int n) {
        // code here
        int currentSqrt = INT_MAX;
        
        for(int i = 0 ; i<= n ; i++)
        {
            int sqre = (i+1)*(i+1);
            
            if(sqre > n)
            {
                break;
            }
            else
            {
                currentSqrt = i+1;
            }
        }
        
        return currentSqrt;
    }
};



/*
    🔴 Optimal

    🧠 Idea:
        - Use Binary Search on the range [0, n].
        - For every middle element, compute its square.
        - If the square equals n, return it.
        - If the square is less than n, it is a valid
          candidate, but a larger one may exist.
        - If the square is greater than n, search the
          left half.

    -------------------------------------------------------

    Why This Works

        If:

            mid² <= n

            - mid is a valid floor square root.
            - Store it as the current best answer.
            - Search the right half for a larger valid
              candidate.

        If:

            mid² > n

            - mid cannot be the answer.
            - Search the left half.

        The variable 'lastValidCandidateElement'
        always stores the largest valid square root
        found so far.

    -------------------------------------------------------

    ⏱️ Time Complexity

        Binary Search:
            O(log N)

        Total:
            O(log N)

    -------------------------------------------------------

    📦 Space Complexity

        Extra Variables:
            O(1)

        Total Auxiliary Space:
            O(1)

    -------------------------------------------------------

    ⚠️ Note

        - For large values of n,

              mid * mid

          can overflow an int.

        - Compute the square as:

              1LL * mid * mid

          or store it in a long long.

    -------------------------------------------------------

    🎯 One Line

        "Use Binary Search to find the largest number whose square is less than or equal to n."
*/
class Solution {
  public:
    int floorSqrt(int n) {
        // code here
        int start = 0 ;
        int end = n;
        int lastValidCandidateElement = INT_MAX;
        while(start <= end)
        {
            int mid = (start + end) /2;
            int sqre = mid*mid;
            
            if(sqre > n)
            {
                end = mid -1 ;
            }
            else if(sqre < n)
            {
                lastValidCandidateElement = mid;
                start = mid + 1;
            }
            else
            {
                return mid;
            }
            
        }
        
        return lastValidCandidateElement;
    }
};