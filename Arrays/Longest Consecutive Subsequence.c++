// https://www.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1

/*
🔴 Longest Consecutive Sequence (Brute Force)

🧠 Idea:
- Treat every element as the starting element of a sequence.
- Keep checking whether the next consecutive element exists.
- Continue until the sequence breaks.
- Track the maximum sequence length.

🧠 Example:
arr = [100,4,200,1,3,2]

Start from 1:
    2 exists
    3 exists
    4 exists

Length = 4

Answer = 4

⚠️ Duplicate Work:

For sequence:

    [1,2,3,4]

Starting from:
    1 → checks 2,3,4
    2 → checks 3,4
    3 → checks 4

The same sequence is explored multiple times.

⏱️ TC:
Outer loop → O(N)

For each element:
    while loop may run O(N)

Each linearSearch → O(N)

Worst Case:
    O(N³)

📦 SC:
O(1)

🎯 One line:
"Start from every element and repeatedly search for the next consecutive number."
*/
class Solution {
  public:

    bool linearSearch(vector<int>& arr , int target)
    {
        for(int i= 0 ;i< arr.size() ; i++)
        {
            if(arr[i] == target)
            {
                return true;
            }
        }
        return false;
    }
    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        // Your code here
        int maxi =0 ;
        for(int i=0; i< arr.size() ; i++)
        {
            int currentElementSteak = 1; 
            int currentElement = arr[i]; 
            
            while(linearSearch(arr, currentElement+1))
            {
                currentElementSteak++;
                currentElement++;
            }
            maxi =max(maxi, currentElementSteak);
            
        }
        return maxi;
    }
};

/*
🔴 Longest Consecutive Sequence (Sorting)

🧠 Idea:
- Sort the array.
- Consecutive numbers will become adjacent.
- Track the current streak length.
- If current element is previous + 1, extend the streak.
- If current element is a duplicate, ignore it.
- Otherwise, sequence breaks → update answer and start a new streak.

🧠 Example:
arr = [100,4,200,1,3,2]

After sorting:

[1,2,3,4,100,200]

Streaks:

1 → 2 → 3 → 4  (length = 4)

Answer = 4

⚠️ Why check:

    arr[i] != previousElement

?

To ignore duplicates.

Example:

[1,2,2,3]

The second 2 should neither extend nor break the streak.

⏱️ TC:
Sorting → O(N log N)
Traversal → O(N)

Overall → O(N log N)

📦 SC:
O(1) (ignoring sorting space)

🎯 One line:
"Sort the array and count consecutive numbers while ignoring duplicates."
*/
class Solution {
  public:

    
    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        // Your code here
        sort(arr.begin() , arr.end());
        int maxi =0 ;
        int currentElementStreak = 1 ;
        int previousElement = arr[0];
        for(int i= 1 ; i < arr.size() ; i++)
        {
            if(arr[i] -1 == previousElement)
            {
                currentElementStreak++;
                
            }
            else if(arr[i] != previousElement)
            {
                maxi = max(maxi, currentElementStreak);
                currentElementStreak = 1; 
            }
            previousElement = arr[i]; 
        }
        maxi = max(maxi, currentElementStreak);
        return maxi;
    }
};


/*
🔴 Longest Consecutive Sequence (Hash Set)

🧠 Idea:
- Store all elements in a hash set.
- For every element, keep checking whether the next
  consecutive element exists in the set.
- Count the streak length and update the maximum.

🧠 Example:
arr = [100,4,200,1,3,2]

Start from 1:
    2 exists
    3 exists
    4 exists

Length = 4

Answer = 4

⚠️ Duplicate values are automatically removed
by the unordered_set.

⚠️ This is better than brute force because
each lookup is O(1) on average instead of O(N).

⚠️ Still not the optimal hash-set solution.
Sequences are explored multiple times.

Example:

[1,2,3,4]

Starting from:
    1 → checks 2,3,4
    2 → checks 3,4
    3 → checks 4

Same sequence is revisited.

⏱️ TC:
Worst Case → O(N²)

📦 SC:
O(N)

🎯 One line:
"Use a hash set for fast lookups and extend every possible sequence."
*/
class Solution {
  public:

    
    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        // Your code here
        unordered_set<int> st; 
        
        int maxi =1 ;
        for(auto x : arr)
        {
            st.insert(x);
        }
        
        for(int i = 0 ; i< arr.size(); i++)
        {
            int currentElement = arr[i] ;
            int currentElementStreak = 1;
            while(st.find(currentElement + 1) != st.end())
            {
                currentElement++;
                currentElementStreak++;
            }
            maxi = max( maxi, currentElementStreak );
        }
        return maxi;
    }
};


/*
🔴 Longest Consecutive Sequence (Optimal Hash Set)

🧠 Idea:
- Store all elements in a hash set for O(1) lookups.
- Only start counting from elements that are the
  beginning of a sequence.

🧠 How to identify a starting element?

    x - 1 does NOT exist

Example:

    [1,2,3,4]

1 is a start      ✅
2 is not          ❌
3 is not          ❌
4 is not          ❌

This avoids exploring the same sequence multiple times.

🧠 Example:
arr = [100,4,200,1,3,2]

Starts:

100 → length = 1
200 → length = 1
1   → 2 → 3 → 4

Length = 4

Answer = 4

⏱️ TC: O(N)
📦 SC: O(N)

🎯 One line:
"Only start counting from sequence starters and extend forward."
*/
class Solution {
  public:

    
    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        // Your code here
        unordered_set<int> st; 
        
        int maxi =1 ;
        for(auto x : arr)
        {
            st.insert(x);
        }
        
        for(auto x : st)
        {
            
            if(st.find(x-1) == st.end())
            {
                int element = x ; 
                int count =1 ;
                
                while(st.find(element+1) != st.end())
                {
                    count++;
                    element++;
                }
                maxi = max(count, maxi);
            }
        }
        return maxi;
    }
};