// https://www.geeksforgeeks.org/problems/implement-upper-bound/1

/*
    🔴 Optimal

    🧠 Idea:
        - Use Binary Search to find the first element
          that is strictly greater than the target.
        - Whenever a value greater than the target is
          found, store its index and continue searching
          on the left for an earlier occurrence.

    -------------------------------------------------------

    Why This Works

        - If arr[mid] <= target, the upper bound must
          lie on the right.

        - If arr[mid] > target, mid is a potential
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

        "Use Binary Search to find the first element strictly greater than the target."
*/
class Solution {
  public:
    int upperBound(vector<int>& arr, int target) {
        // code here
        
        int index = arr.size();
        int start = 0 ; 
        int end = arr.size()-1 ;
        
        while(start <= end )
        {
            int mid = (start + end ) /2;
            
            if(arr[mid] < target)
            {
                
                start = mid + 1; 
            }
            else if(arr[mid] > target)
            {
                index = mid;
                end = mid -1 ;
            }
            else if(arr[mid] == target)
            {
                // index = mid; 
                start = mid + 1; 
            }
        }
        
        return index;
    }
};
