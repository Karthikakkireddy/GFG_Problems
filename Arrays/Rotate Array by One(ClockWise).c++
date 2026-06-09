// https://www.geeksforgeeks.org/problems/cyclically-rotate-an-array-by-one2614/1


/*
🔴 Intuition

- The goal is:
      Last element becomes first
      All other elements shift right by one position.

- Start from the last index.

- Swap the last element with its previous element.
  This moves the last element one step closer to index 0.

- Keep moving left and repeating the swap.

- After every swap, the original last element
  advances one position towards the front.

- Continue until it reaches index 0.

------------------------------------------------------

🧠 Example:

    [1,2,3,4,5]

    swap(5,4) → [1,2,3,5,4]
    swap(5,3) → [1,2,5,3,4]
    swap(5,2) → [1,5,2,3,4]
    swap(5,1) → [5,1,2,3,4]

------------------------------------------------------

⏱️ TC: O(N)
📦 SC: O(1)

🎯 One line:

"Repeatedly swap the last element leftwards until it reaches the front."
*/
class Solution {
  public:
    void rotate(vector<int> &arr) {
        // code here
        int n = arr.size();
        for(int i=n-1 ; i>0 ; i--)
        {
            swap(arr[i],arr[i-1]);
        }
    }
};