// https://www.geeksforgeeks.org/problems/subset-sums2234/1



/*
    Approach: Recursion (Pick / Not Pick)

------------------------------------------------------

    What we are doing:

    - For every element, we have 2 choices:
        → pick it → add to sum
        → not pick it → ignore

    - At the end (index == n),
      the current sum represents one subset

------------------------------------------------------

    How recursion works:

        subsetSumsHelper(index, sum)

        → pick:
            sum + arr[index]

        → not pick:
            sum (no change)

------------------------------------------------------

    Base Case:

        if(index == arr.size())
        {
            res.emplace_back(sum);
            return;
        }

    - When all elements are processed,
      we store the final sum

------------------------------------------------------

    Example: arr = [1,2]

        index=0
        ├── pick 1 → sum=1
        │   ├── pick 2 → sum=3 → store
        │   └── not pick 2 → sum=1 → store
        │
        └── not pick 1 → sum=0
            ├── pick 2 → sum=2 → store
            └── not pick 2 → sum=0 → store

        Result:
            [3,1,2,0]

------------------------------------------------------

    Recursion Tree:

        (0,0)
        ├── (1,1)
        │   ├── (2,3)
        │   └── (2,1)
        └── (1,0)
            ├── (2,2)
            └── (2,0)

------------------------------------------------------

    Why this works:

    - Each element doubles possibilities
    - Total subsets = 2^N
    - Each path represents one subset

------------------------------------------------------

    Time Complexity: O(2^N)

    - Each element → 2 choices

------------------------------------------------------

    Space Complexity: O(N)

    - Recursion depth

------------------------------------------------------

    Difference from for-loop version:

        Pick/Not Pick:
            ✔ Explicit binary decisions
            ✔ Clear subset formation

        For-loop:
            ✔ More compact
            ✔ Preferred for combinations

------------------------------------------------------

    Key Takeaway:

    ✔ Classic subset generation pattern
    ✔ Very intuitive for understanding recursion
*/
class Solution {
  public:
  
    void subsetSumsHelper(vector<int> &arr , vector<int> &res, int sum, int index)
    {
        if(index == arr.size())
        {
            res.emplace_back(sum);
            return ; 
        }
        subsetSumsHelper(arr , res, sum+ arr[index] , index+1);// pick
        subsetSumsHelper(arr, res , sum + 0 , index+1); // not pick
        
        
    }
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        int index =0 ;
        vector<int> res; 
        int sum = 0 ; 
        subsetSumsHelper(arr, res, sum,index );
        return res;
    }
};

/*
    Approach: Backtracking (For-loop) to generate subset sums

------------------------------------------------------

    What we are doing:

    - Instead of storing subsets, we store their SUM
    - At every recursion level:
        → current sum represents one subset
        → so we add it immediately to result

------------------------------------------------------

    Key idea:

        res.emplace_back(sum);

    - Every state = one valid subset
    - So we don't wait for base case

------------------------------------------------------

    How recursion works:

        subsetSumsHelper(index, sum)

        for(i = index → n-1)
            include arr[i] → sum + arr[i]
            recurse with i+1

------------------------------------------------------

    Example: arr = [1,2]

        Start:
            sum = 0 → add 0

        Pick 1:
            sum = 1 → add 1

            Pick 2:
                sum = 3 → add 3

        Backtrack:
            Pick 2:
                sum = 2 → add 2

        Final result:
            [0,1,3,2]

------------------------------------------------------

    Recursion Tree:

        sum=0
        ├── +1 → sum=1
        │   ├── +2 → sum=3
        │   └── (stop)
        └── +2 → sum=2

------------------------------------------------------

    Why this works:

    - Each recursive path represents a subset
    - Instead of storing elements, we accumulate sum

------------------------------------------------------

    Time Complexity: O(2^N)

    - Total subsets = 2^N
    - Each subset contributes one sum

------------------------------------------------------

    Space Complexity: O(N)

    - Recursion depth = N

    (Result array takes O(2^N), not counted as auxiliary)

------------------------------------------------------

    Key Takeaway:

    ✔ Same pattern as subsets
    ✔ Just store "sum" instead of subset
    ✔ Very clean and efficient
*/
class Solution {
  public:
  
    void subsetSumsHelper(vector<int> &arr , vector<int> &res, int sum, int index)
    {
        res.emplace_back(sum);
        
        for(int i = index;  i< arr.size() ; i++)
        {
           subsetSumsHelper(arr, res, sum + arr[i], i+1); 
        }
    }
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        int index =0 ;
        vector<int> res; 
        int sum = 0 ; 
        subsetSumsHelper(arr, res, sum,index );
        return res;
    }
};