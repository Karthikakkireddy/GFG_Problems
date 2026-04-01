// https://www.geeksforgeeks.org/problems/power-set4302/1


/*
    Approach: Backtracking (Generate all subsequences)

------------------------------------------------------

    What we are doing:

    - Generate ALL possible subsequences of string `s`
    - At every step:
        → current `temp` is one valid subsequence
        → so we add it immediately

------------------------------------------------------

    How recursion works:

        helper(index, temp)

        for(i = index → n-1)
            pick s[i]
            recurse with i+1
            backtrack

------------------------------------------------------

    Example: s = "ab"

        ""
        ├── "a"
        │   └── "ab"
        └── "b"

        Result:
            ["", "a", "ab", "b"]

------------------------------------------------------

    Why this works:

    - Each character can be:
        ✔ included
        ✔ or skipped (implicitly by loop)

    - Loop handles "not pick" implicitly
    - Recursion handles "pick"

------------------------------------------------------

    Important detail:

        ans.push_back(temp);

    👉 Happens at EVERY level
    👉 So even "" (empty string) is included

------------------------------------------------------

    Time Complexity: O(2^N * N)

    - Total subsequences = 2^N
    - Copying each string → O(N)

------------------------------------------------------

    Space Complexity: O(N)

    - Recursion depth = N
    - temp string size ≤ N

------------------------------------------------------

    ⚠️ Problem-specific issue (important):

        GFG version of this problem expects:
            ❌ EXCLUDE empty string

    But your code includes:
            ""  ← unwanted

------------------------------------------------------

    Fix:

        Instead of pushing at start:

            if(!temp.empty())
                ans.push_back(temp);

------------------------------------------------------

    Another small optimization:

        Sorting:
            sort(ans.begin(), ans.end());

        → takes O(2^N log 2^N)

------------------------------------------------------

    Final Takeaway:

    ✔ Classic subsequence generation
    ✔ Loop-based backtracking
    ⚠️ Remember to exclude "" if required
*/
class Solution {
  public:
    void AllPossibleStringsHelper(vector<string> &ans,
                                    string &s, string &temp, int index)
    {
        ans.push_back(temp);
        
        for(int i=index ; i < s.length() ; i++)
        {
            temp.push_back(s[i]);
            AllPossibleStringsHelper(ans, s, temp, i+1);
            temp.pop_back();
        }
    }
    vector<string> AllPossibleStrings(string s) {
        // Code here
        string temp = "";
        vector<string> ans;
        int index= 0;
        AllPossibleStringsHelper(ans, s, temp, index);
        sort(ans.begin(), ans.end());
        return ans;
    }
};




/*
    Approach (Pick / Not Pick):

    - At every index, we have 2 choices:
        1. Pick the current character
        2. Do NOT pick the current character

    - This forms a recursion tree of size 2^N (all subsequences)

    ------------------------------------------------------

    Why this works:

    - Every subsequence is just a combination of pick / not pick decisions.
    - By exploring both choices at every index, we guarantee covering ALL possibilities.

    Example: "ab"

        index 0:
            pick 'a' → "a"
                index 1:
                    pick 'b' → "ab"
                    not pick → "a"

            not pick → ""
                index 1:
                    pick 'b' → "b"
                    not pick → ""

    ------------------------------------------------------

    Important detail:

    - We skip adding empty string ("") using:
        if(!temp.empty())

    ------------------------------------------------------

    Why sorting at the end?

    - Recursion generates subsequences in structural order, NOT lexicographical order.
    - GFG expects sorted output → so we sort the final result.

    ------------------------------------------------------

    Time Complexity:

        O(2^N * N)
        - 2^N subsequences
        - each takes O(N) to copy

    Space Complexity:

        O(N) recursion stack
        + O(2^N * N) for storing results
*/

class Solution {
  public:
    void AllPossibleStringsHelper(vector<string> &ans,
                                    string &s, string &temp, int index)
    {
        if(index == s.length())
        {
             if(!temp.empty())
                ans.push_back(temp);
            return;
        }

        // pick
        temp.push_back(s[index]);
        AllPossibleStringsHelper(ans, s, temp, index+1);

        // backtrack
        temp.pop_back();

        // not pick
        AllPossibleStringsHelper(ans, s, temp, index+1);
    }

    vector<string> AllPossibleStrings(string s) {
        string temp = "";
        vector<string> ans;

        AllPossibleStringsHelper(ans, s, temp, 0);

        sort(ans.begin(), ans.end()); // required by GFG

        return ans;
    }
};