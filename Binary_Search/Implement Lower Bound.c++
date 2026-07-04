// https://www.geeksforgeeks.org/problems/implement-lower-bound/1


class Solution {
  public:
    int lowerBound(vector<int>& arr, int target) {
        // code here
        int index = arr.size();
        int start = 0 ; 
        int end = arr.size() -1 ; 
        
        while(start <= end)
        {
            int mid = (start+end) /2 ;
            
            if(arr[mid] < target)
            {
                start = mid +1;
            }
            else if(arr[mid] > target)
            {
                index = mid;
                end = mid -1 ;
            }
            else if(arr[mid] == target)
            {
                index = mid ;
                end = mid -1;
            }
        }
        
        return index;
    }
};

/*
    🔴 Optimal

    🧠 Idea:
        - Use Binary Search to find the first element
          that is greater than or equal to the target.
        - Whenever a valid candidate is found, store
          its index and continue searching on the left
          to see if an earlier occurrence exists.

    -------------------------------------------------------

    Why This Works

        - If arr[mid] < target, the lower bound must
          lie on the right.

        - If arr[mid] >= target, mid is a potential
          answer, but there may be an earlier one on
          the left.

        - The variable 'index' always stores the best
          candidate found so far.

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

    🎯 One Line

        "Use Binary Search to find the first element greater than or equal to the target."
*/
