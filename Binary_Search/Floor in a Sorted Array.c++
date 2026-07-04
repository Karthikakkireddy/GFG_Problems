// https://www.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1

/*
    🔴 Optimal

    🧠 Idea:
        - Use Binary Search to find the largest element
          that is less than or equal to the target.
        - Whenever a valid candidate is found, store
          its index and continue searching on the right
          to see if there is a larger valid element.

    -------------------------------------------------------

    Why This Works

        - If arr[mid] <= target, mid is a potential
          floor, but there may be a larger valid element
          on the right.

        - If arr[mid] > target, the floor must lie
          on the left.

        - The variable 'index' always stores the best
          floor found so far.

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

        "Use Binary Search to find the largest element less than or equal to the target."
*/
class Solution {
  public:
    int findFloor(vector<int>& arr, int target) {
        // code here
        int index = -1 ; 
        int start = 0 ; 
        int end = arr.size()-1 ; 
        
        while(start <= end)
        {
            int mid = (start + end ) / 2; 
            
            if(arr[mid] < target)
            {
                index = mid ; 
                start = mid + 1; 
            }
            else if(arr[mid] > target )
            {
                end = mid -1 ;
            }
            else 
            {
                index = mid ; 
                start = mid + 1 ;
            }
        }
        
        return index ; 
    }
};
