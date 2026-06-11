// https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1



/*
🔴 Longest Subarray with Sum = K (Brute Force)

🧠 Idea:
- Consider every possible subarray.
- Fix a starting index.
- Keep extending the ending index while maintaining the sum.
- Whenever sum becomes k, update the longest length.

🧠 Example:
arr = [1,2,3,1,1]
k = 6

start = 0:
    [1]      → 1
    [1,2]    → 3
    [1,2,3]  → 6 ✅ len = 3
    [1,2,3,1]→ 7
    ...

start = 1:
    [2]      → 2
    [2,3]    → 5
    [2,3,1]  → 6 ✅ len = 3

Longest = 3

🧠 Why currentSum is outside inner loop?
- For a fixed startIndex, we keep extending the subarray.
- Instead of recomputing the sum from scratch, keep adding arr[endIndex].

⏱️ TC: O(N²)
📦 SC: O(1)

🎯 One line:
"Generate every subarray and track the longest one whose sum equals k."
*/

class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int longestLen = 0 ; 
       for(int startIndex = 0 ; startIndex< arr.size() ; startIndex++)
       {
           int currentSum = 0;
           
           for(int endIndex = startIndex ; endIndex < arr.size() ; endIndex++ )
           {
               currentSum += arr[endIndex]; 
               
               if(currentSum == k)
               {
                   longestLen = max(longestLen, endIndex - startIndex + 1);
               }
           }
       }
       
       return longestLen;
    }
};



// Q) Where can a valid subarray exist?
//
// A) Three possibilities:
//
// 1. It starts from index 0 and ends at some index j.
//    Example:
//    [0 ... j]
//
// 2. It starts somewhere in the middle and ends at the last index.
//    Example:
//    [i ... n-1]
//
// 3. It starts and ends somewhere in the middle.
//    Example:
//    [i ... j]
//    where 0 < i <= j < n-1
//
// The third case is the tricky one because there can be many such
// subarrays and checking all of them directly would be expensive.


// Q) Suppose we are currently at index 2.
//    What subarrays can end at index 2?
//
// A)
//
//    [2]
//    [1,2]
//    [0,1,2]
//
// Any valid subarray ending at index 2 must be one of these.


// Q) How can we determine whether one of these middle subarrays is valid?
//
// A) Instead of checking every subarray directly, let's keep a running
//    sum from index 0 to the current index.
//
//    x = arr[0] + arr[1] + ... + arr[i]
//
//    Assume there exists a valid subarray ending at i whose sum is k.
//
//    Then:
//
//    x = (sum before the subarray starts) + k
//
//    Therefore:
//
//    sum before the subarray starts = x - k


// Example:
//
// arr = [3, 4, 5]
// k = 9
//
// At index 2:
//
// x = 3 + 4 + 5 = 12
//
// Assume [4,5] is the valid subarray.
//
// Then:
//
// 12 = 3 + 9
//
// Therefore:
//
// 12 - 9 = 3
//
// Notice that 3 is exactly the running sum we had seen earlier.
//
// So instead of searching for the subarray directly,
// we search for a previous running sum equal to (x - k).


// If we have already seen:
//
// previousRunningSum = x - k
//
// Then:
//
// x - previousRunningSum = k
//
// This means the elements between those two positions
// form a valid subarray with sum k.


// Therefore, while traversing the array:
//
// 1. Calculate current running sum x.
// 2. Check whether (x - k) has been seen before.
// 3. If yes, a valid subarray exists.
// 4. Store the current running sum for future indices.


// We store:
//
// runningSum -> first index where it appeared
//
// so that future indices can quickly check whether
// (currentRunningSum - k) has already occurred.
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
       int longestLen = 0; 
       map<long long, int> mp; 
       long long sum = 0;
       for(int i=0 ; i< arr.size() ; i++)
       {
           sum += arr[i]; 
           
           if(sum == k)
           {
               longestLen = max(longestLen, i+1);
           }
           else if(mp.find(sum-k) != mp.end())
           {
               longestLen = max(longestLen, i - mp[sum-k]);
           }
           if(mp.find(sum) == mp.end()) // VVVVVVVIMP line - Edge case - Figure out why we need this? 
           {
                mp[sum] = i;
           }
       }
       
       return longestLen;
    }
};