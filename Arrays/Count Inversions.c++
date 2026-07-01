// https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1

/*
    🔴 Brute Force

    🧠 Idea:
        - Generate every possible pair (i, j)
          where i < j.
        - If arr[i] > arr[j], it forms an inversion.
        - Count all such inversions.

    -------------------------------------------------------

    Why This Works

        - Every valid pair is checked exactly once.
        - Whenever the left element is greater than the
          right element, the pair satisfies the inversion
          condition.

    -------------------------------------------------------

    ⏱️ Time Complexity

        Outer Loop:
            O(N)

        Inner Loop:
            O(N)

        Total:
            O(N²)

    -------------------------------------------------------

    📦 Space Complexity

        Extra Variables:
            O(1)

        Total Auxiliary Space:
            O(1)

    -------------------------------------------------------

    🎯 One Line

        "Check every pair and count those where the left element is greater than the right element."
*/
class Solution {
  public:
    int inversionCount(vector<int> &arr) {
        // Code Here
        int count = 0 ;
        int n = arr.size(); 
        for(int i= 0 ; i< n; i++ )
        {
            for(int j = i+1 ; j< n ; j++)
            {
                if(arr[i] > arr[j])
                {
                    count++;
                }
            }
        }
        
        return count;
    }
};

/*
    🔴 Optimal

    🧠 Idea:
        - Use Merge Sort to divide the array into
          smaller sorted halves.
        - While merging two sorted halves, count
          inversions across the halves.
        - If:

              arr[left] > arr[right]

          then all elements from left to mid are also
          greater than arr[right], because the left half
          is already sorted.

        - Therefore, add:

              mid - left + 1

          inversions at once.

    -------------------------------------------------------

    Why This Works

        - Merge Sort guarantees both halves are sorted
          before merging.
        - Instead of checking every pair individually,
          one comparison counts multiple inversions.

    -------------------------------------------------------

    ⏱️ Time Complexity

        Merge Sort Divisions:
            O(log N) levels

        Merge at Each Level:
            O(N)

        Total:
            O(N log N)

    -------------------------------------------------------

    📦 Space Complexity

        Temporary Array (temp):
            O(N)

        Recursive Call Stack:
            O(log N)

        Total Auxiliary Space:
            O(N)

    -------------------------------------------------------

    🎯 One Line

        "Count inversions during merge by using the fact that both halves are already sorted."
*/
class Solution {
  public:
  
    void merge(vector<int> &arr, int &count , int start ,int mid, int end )
    {
        int left = start; 
        int right = mid+1;
        
        vector<int> temp ; 
        
        while(left <= mid && right <= end )
        {
            if(arr[left] <= arr[right])
            {
                temp.push_back(arr[left]);
                left++;
            }
            else
            {
                count = count + (mid - left + 1);
                temp.push_back(arr[right]);
                right++;
            }
        }
        while(left <= mid)
        {
            temp.push_back(arr[left]);
            left++;
        }
        while(right <= end)
        {
            temp.push_back(arr[right]);
            right++;
        }
        
        int tempPointer = 0; 
        int vectorPointer = start ;
        while(vectorPointer <= end)
        {
            arr[vectorPointer] = temp[tempPointer];
            tempPointer++;
            vectorPointer++; 
        }
    }
    void mergeSort(vector<int> &arr,  int &count , int start , int end )
    {
        if(start >= end)
        {
            return ;
        }
        
        int mid = ( start + end ) / 2 ;
        
        mergeSort(arr, count , start, mid);
        mergeSort(arr, count, mid+1, end);
        
        merge(arr, count, start, mid, end); 
        
    }
    int inversionCount(vector<int> &arr) {
        // Code Here
        int count = 0 ;
        int n = arr.size(); 
        mergeSort(arr, count , 0 , n-1);
        
        return count;
    }
};