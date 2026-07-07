// https://www.geeksforgeeks.org/problems/find-nth-root-of-m5843/1

/*
    🔴 Brute Force

    🧠 Idea:
        - Try every possible integer from 1 to m.
        - For each number, compute its nth power.
        - If the nth power equals m, return the number.
        - If the nth power exceeds m, stop searching
          since larger numbers will only produce larger powers.

    -------------------------------------------------------

    Why This Works

        - The nth root of m is an integer x such that:

              xⁿ = m

        - By checking every possible candidate in
          increasing order, the first exact match is
          the required nth root.

        - If xⁿ becomes greater than m, no larger value
          can satisfy the condition.

    -------------------------------------------------------

    ⏱️ Time Complexity

        Outer Loop:
            O(m)

        Computing nth Power:
            O(n)

        Total:
            O(m × n)

    -------------------------------------------------------

    📦 Space Complexity

        Extra Variables:
            O(1)

        Total Auxiliary Space:
            O(1)

    -------------------------------------------------------

    ⚠️ Note

        - The variable 'product' can overflow for
          large values of n and m.

        - Use long long for multiplication and stop
          computing once product exceeds m.

    -------------------------------------------------------

    🎯 One Line

        "Try every possible integer and check whether its nth power equals m."
*/
class Solution {
  public:
    int nthRoot(int n, int m) {
        // Code here
        if(m == 0 || m ==1 )
        {
            return m; 
        }
        if(n==1)
        {
            return m;
        }
        
        
        int start = 2;
        int end = m; 
        
        
        while(start <= end)
        {
            int mid = (start + end) /2 ;
            int product =1; 
            for(int i= 1 ; i<= n; i++)
            {
                product = product * mid;
            }
            
            if(product > m)
            {
                end = mid -1 ; 
            }
            else if(product < m)
            {
                start = mid +1 ; 
            }
            else
            {
                return mid;
            }
        }
        
        return -1;
    }
};

/*
    🔴 Optimal

    🧠 Idea:
        - Use Binary Search on the range [1, m].
        - For every middle element, compute its nth power.
        - If the nth power equals m, return the middle element.
        - If the nth power is less than m, search the right half.
        - If the nth power is greater than m, search the left half.

    -------------------------------------------------------

    Why This Works

        If:

            midⁿ < m

            - The nth root must be larger.
            - Search the right half.

        If:

            midⁿ > m

            - The nth root must be smaller.
            - Search the left half.

        If:

            midⁿ == m

            - mid is the required nth root.

        Since the search space is halved every iteration,
        Binary Search efficiently finds the answer.

    -------------------------------------------------------

    ⏱️ Time Complexity

        Binary Search:
            O(log M)

        Computing midⁿ:
            O(N)

        Total:
            O(N × log M)

    -------------------------------------------------------

    📦 Space Complexity

        Extra Variables:
            O(1)

        Total Auxiliary Space:
            O(1)

    -------------------------------------------------------

    ⚠️ Note

        - 'product' can overflow while computing midⁿ.

        - Use long long and stop multiplication early
          if the product exceeds m.

    -------------------------------------------------------

    🎯 One Line

        "Use Binary Search to find the integer whose nth power equals m."
*/
class Solution {
  public:
    int nthRoot(int n, int m) {
        // Code here
        if(m == 0 || m ==1 )
        {
            return m; 
        }
        if(n==1)
        {
            return m;
        }
        
        
        int start = 2;
        int end = m; 
        
        
        while(start <= end)
        {
            int mid = (start + end) /2 ;
            int product =1; 
            for(int i= 1 ; i<= n; i++)
            {
                product = product * mid;
            }
            
            if(product > m)
            {
                end = mid -1 ; 
            }
            else if(product < m)
            {
                start = mid +1 ; 
            }
            else
            {
                return mid;
            }
        }
        
        return -1;
    }
};