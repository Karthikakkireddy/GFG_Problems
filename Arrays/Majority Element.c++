// https://www.geeksforgeeks.org/problems/majority-element-1587115620/1

/*
🔴 Majority Element (Hash Map)

🧠 Idea:
- Count the frequency of every element.
- Majority element appears more than n/2 times.
- Traverse the map and return the element whose frequency
  exceeds n/2.

🧠 Example:
arr = [2,2,1,1,1,2,2]

2 → 4
1 → 3

4 > 7/2

Answer = 2

⏱️ TC: O(N)
📦 SC: O(N)

🎯 One line:
"Count frequencies and return the element appearing more than n/2 times."
*/
class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        // code here
        unordered_map<int, int> mp; 
        int n = arr.size();
        
        for(int i=0 ; i< n ; i++)
        {
            mp[arr[i]]++;
        }
        
        for(auto x : mp)
        {
            if(x.second > n/2)
            {
                return x.first;
            }
        }
        
        return -1;
    }
};



class Solution {
  public:
    int majorityElement(vector<int>& nums) {
        // Boyer-Moore Voting Algorithm

        // Phase 1: Find a potential majority element.
        //
        // Key observation:
        // - If two different elements are paired together, they cancel each other out.
        // - A true majority element (> n/2 occurrences) can never be completely cancelled.
        // - Therefore, after all cancellations, the remaining candidate (if any)
        //   must be the majority element.
        //
        // Note:
        // After this phase, 'current' is only a CANDIDATE.
        // It is NOT guaranteed to be the majority element.

        int current;
        int count = 0;

        for(int i = 0; i < n; i++)
        {
            if(count == 0)
            {
                current = nums[i];
                count = 1;
            }
            else if(nums[i] == current)
            {
                count++;
            }
            else
            {
                count--;
            }
        }

        // Phase 2: Verify the candidate.
        //
        // Why verification is needed:
        // Example: [1, 2, 3, 4]
        //
        // The first phase will still produce some candidate,
        // even though no majority element exists.
        //
        // Therefore, count the occurrences of the candidate
        // and check whether it appears more than n/2 times.

        int verifyCount = 0;

        for(auto x : nums)
        {
            if(x == current)
            {
                verifyCount++;
            }
        }

        // If candidate occurs more than n/2 times,
        // it is the majority element.
        // Otherwise, no majority element exists.

        return (verifyCount > n / 2) ? current : -1;
    }
};