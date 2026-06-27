// https://www.geeksforgeeks.org/problems/count-subarray-with-given-xor/1

// Helpful for calculating - https://chatgpt.com/share/6a3fa542-5394-83e8-bf29-75d2a83e7103

/*
    🔴 Brute Force

    🧠 Idea:
        - Consider every possible subarray.
        - Maintain the XOR while extending the subarray.
        - If the current XOR equals k, increment the count.

    -------------------------------------------------------

    Why This Works

        - Every subarray is generated exactly once.
        - Instead of recomputing XOR from scratch,
          keep updating it by XORing the next element.

    -------------------------------------------------------

    ⏱️ Time Complexity

        Outer Loop:
            O(N)

        Inner Loop:
            O(N)

        XOR Update:
            O(1)

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

        "Generate every subarray, maintain its XOR, and count those whose XOR equals k."
*/
class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        long count = 0 ;
        int n = arr.size(); 
        for(long i = 0 ; i< n ;i++)
        {
            int xor1  = 0;
            for(long j= i ; j< n ; j++)
            {
                xor1 ^= arr[j];
                
                if(xor1 == k)
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
        - Maintain the prefix XOR while traversing the array.
        - Let prefixXor be the XOR from index 0 to i.
        - We need a previous prefix XOR such that:

              previousPrefixXor ^ prefixXor = k

        - Rearranging:

              previousPrefixXor = prefixXor ^ k

        - Store the frequency of every prefix XOR in a hash map.
        - For every element, check how many times
          (prefixXor ^ k) has already occurred.

    -------------------------------------------------------

    Why This Works

        - XOR of a subarray is:

              prefixXor ^ previousPrefixXor

        - Therefore, whenever a previous prefix XOR equals
          (prefixXor ^ k), a valid subarray is found.
        - Hash map stores frequencies, allowing multiple
          subarrays ending at the current index to be counted.

    -------------------------------------------------------

    ⏱️ Time Complexity

        Single Traversal:
            O(N)

        Hash Map Operations:
            O(1) average per element

        Total:
            O(N)

    -------------------------------------------------------

    📦 Space Complexity

        Hash Map:
            Stores prefix XOR frequencies

        Worst Case:
            O(N)

    -------------------------------------------------------

    🎯 One Line

        "Store prefix XOR frequencies and use XOR properties to count valid subarrays in one traversal."
*/
class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        long count = 0 ;
        int n = arr.size(); 
        unordered_map<int,int> mp; 
        int prefiXor = 0;
        for(long i = 0 ; i< n ;i++)
        {
            prefiXor ^= arr[i];
            
            if(prefiXor == k)
            {
                count++;
            }
            if(mp.find( k ^ prefiXor) != mp.end())
            {
                count = count + mp[k^prefiXor   ];
            }
            
            mp[prefiXor]++;
        }
        
        return count;
    }
};