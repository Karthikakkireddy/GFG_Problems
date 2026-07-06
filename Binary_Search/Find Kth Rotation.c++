// https://www.geeksforgeeks.org/problems/rotation4723/1


/*
    🔴 Optimal

    🧠 Idea:
        - The number of rotations equals the index of
          the minimum element.
        - Use Binary Search to locate the minimum element.
        - In every iteration, determine which half is sorted.
        - Update the minimum element and its index from
          the sorted half, then continue searching in
          the unsorted half.

    -------------------------------------------------------

    Why This Works

        Left Half is Sorted:

            arr[start] <= arr[mid]

            - arr[start] is the smallest element in
              the left half.
            - Update the minimum if needed.
            - Search the right half.

        Right Half is Unsorted:

            arr[start] > arr[mid]

            - Rotation lies in the left half.
            - arr[mid] is a candidate for the minimum.
            - Update the minimum if needed.
            - Search the left half.

        At the end, the index of the minimum element
        equals the number of rotations.

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

        "Use Binary Search to find the minimum element; its index gives the number of rotations."
*/
class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int minimumElement = INT_MAX; 
        int mimimumIndex = -1; 
        
        int start = 0 ;
        int end = arr.size() -1; 
        
        while(start <= end)
        {
            int mid = (start + end ) /2; 
            
            if(arr[start] <= arr[mid])
            {
                if(arr[start] < minimumElement)
                {
                    minimumElement = arr[start];
                    mimimumIndex = start;
                }
                start = mid + 1;
            }
            else
            {
                if(arr[mid] < minimumElement)
                {
                    minimumElement = arr[mid];
                    mimimumIndex = mid;
                }
                end = mid -1 ;
            }
        }
        
        return mimimumIndex ;
    }
};
