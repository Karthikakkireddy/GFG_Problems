// https://www.geeksforgeeks.org/problems/ceil-in-a-sorted-array/1

/*
    🔴 Optimal

    🧠 Idea:
        - Use Binary Search to find the smallest element
          that is greater than or equal to the target.
        - Whenever a valid candidate is found, store
          its index and continue searching on the left
          to see if there is a smaller valid element.

    -------------------------------------------------------

    Why This Works

        - If arr[mid] >= target, mid is a potential
          ceil, but there may be a smaller valid element
          on the left.

        - If arr[mid] < target, the ceil must lie
          on the right.

        - The variable 'index' always stores the best
          ceil found so far.

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

        "Use Binary Search to find the smallest element greater than or equal to the target."
*/
class Solution {
  public:
    int findCeil(vector<int>& arr, int x) {
        // code here
        int index = -1 ;
        
        int start =0 ;
        int end = arr.size() -1 ;
        
        while(start <= end )
        {
            int mid = (start + end ) /2;
            
            if(arr[mid] < x)
            {
                start =mid +1; 
            }
            else if(arr[mid ] > x)
            {
                index= mid;
                end = mid-1;
            }
            else
            {
                index = mid;
                end = mid -1;
            }
        }
        
        return index;
    }
};