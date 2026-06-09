// https://www.geeksforgeeks.org/problems/check-if-an-array-is-sorted0701/1


class Solution {
  public:
    bool isSorted(vector<int>& arr) {
        // code here
        int current = arr[0];
        
        for(auto x : arr)
        {
            if(current > x)
                return false;
            current = x; 
        }
        return true;
    }
};