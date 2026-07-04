// https://www.geeksforgeeks.org/problems/number-of-occurrence2259/1

/*
    🔴 Optimal

    🧠 Idea:
        - Use Binary Search twice:
            1. Find the first occurrence of the target.
            2. Find the last occurrence of the target.
        - If the target is not found, its frequency is 0.
        - Otherwise:

              Frequency = lastIndex - firstIndex + 1

    -------------------------------------------------------

    Why This Works

        Finding First Occurrence:
            - When target is found, store its index.
            - Continue searching on the left to find
              an earlier occurrence.

        Finding Last Occurrence:
            - When target is found, store its index.
            - Continue searching on the right to find
              a later occurrence.

        Since the array is sorted, all occurrences of
        the target are contiguous.

    -------------------------------------------------------

    ⏱️ Time Complexity

        Find First Occurrence:
            O(log N)

        Find Last Occurrence:
            O(log N)

        Frequency Calculation:
            O(1)

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

        "Use Binary Search to find the first and last occurrence, then compute their distance."
*/
class Solution {
  public:
  
    int findFirst(vector<int> &arr, int target)
    {
        int index = -1 ; 
        int start = 0 ; 
        int end = arr.size(); 
        
        while(start <= end)
        {
            int mid = (start + end) /2;
            
            if(arr[mid] < target)
            {
                start = mid +1;
            }
            else if(arr[mid] > target)
            {
                end = mid -1; 
            }
            else
            {
                index = mid ;
                end = mid - 1;
            }
        }
        
        return index;
    }
    
    int findSecond(vector<int> &arr, int target)
    {
        int index = -1 ; 
        int start = 0 ; 
        int end = arr.size(); 
        
        while(start <= end)
        {
            int mid = (start + end) /2;
            
            if(arr[mid] < target)
            {
                start = mid +1;
            }
            else if(arr[mid] > target)
            {
                end = mid -1; 
            }
            else
            {
                index = mid ;
                start = mid +1;
            }
        }
        
        return index;
    }
    int countFreq(vector<int>& arr, int target) {
        // code here
        int first = findFirst(arr, target);
        
        if(first == -1 )
        {
            return 0; 
        }
        
        int second = findSecond(arr,target);
        
        return (second - first ) +1 ;
    }
};
