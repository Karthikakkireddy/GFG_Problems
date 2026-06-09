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


/*
🔴 Intuition

- The last element is the only element that changes its relative position completely.
- Store it before modifying the array.

      temp = arr[n-1]

- Shift every other element one position to the right.

      arr[i+1] = arr[i]

- Start from right to left.
  Otherwise we would overwrite values that are still needed.

------------------------------------------------------

🧠 Example:

    [1,2,3,4,5]

    temp = 5

    i=3 → [1,2,3,4,4]
    i=2 → [1,2,3,3,4]
    i=1 → [1,2,2,3,4]
    i=0 → [1,1,2,3,4]

    arr[0] = temp

    [5,1,2,3,4]

------------------------------------------------------

🧠 Why move from right to left?

If we move left to right:

    arr[i+1] = arr[i]

then values get overwritten before they are copied.

So we start from the end and work backwards.

------------------------------------------------------

⏱️ TC: O(N)

📦 SC: O(1)

------------------------------------------------------

🎯 One line:

"Store the last element, shift everything right, then place the stored element at index 0."
*/
class Solution {
  public:
    void rotate(vector<int> &arr) {
        // code here
        int temp = arr[arr.size()-1];
        for(int i= arr.size()-2 ; i>=0 ; i--)
        {
            arr[i+1] = arr[i];
        }
        arr[0] = temp;
    }
};