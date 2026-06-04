// https://www.geeksforgeeks.org/problems/largest-element-in-array4009/1#

class Solution {
  public:
    int largest(vector<int> &arr) {
        // code here
        int largestNum = INT_MIN;
        
        for(auto x : arr)
        {
            largestNum = max(largestNum, x);
        }
        return largestNum;
    }
};
