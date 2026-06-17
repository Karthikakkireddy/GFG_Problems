// https://www.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1


/*
🔴 Sort an Array of 0s, 1s and 2s (Dutch National Flag Algorithm)

🧠 Idea:
- Maintain three regions:

    [0 ... zero-1]      → all 0s
    [zero ... regular-1] → all 1s
    [regular ... two]    → unknown elements
    [two+1 ... n-1]      → all 2s

- regular explores the unknown region.

🧠 What to do?

If arr[regular] == 0:
    swap with zero region
    zero++
    regular++

If arr[regular] == 1:
    already in correct region
    regular++

If arr[regular] == 2:
    swap with two region
    two--
    do NOT move regular

🧠 Why not increment regular after finding 2?
- After swapping, a new element comes to regular.
- We haven't processed it yet.
- So regular must stay and examine it.

🧠 Example:
[2,0,2,1,1,0]

Process elements and gradually build:
    0-region on left
    2-region on right

Result:
[0,0,1,1,2,2]

⏱️ TC: O(N)
📦 SC: O(1)

🎯 One line:
"Use three pointers to partition the array into 0s, 1s, and 2s in a single pass."
*/
class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        
        int zero =0 ;
        int regular =0 ; 
        int two =arr.size()-1;
        
        while(regular <= two)
        {
            if(arr[regular] == 0)
            {
                swap(arr[regular], arr[zero]);
                zero++;
                regular++;
            }
            else if(arr[regular] == 1)
            {
                regular++;
            }
            else if(arr[regular] == 2)
            {
                swap(arr[regular], arr[two]);
                two--;
            }
        }
    }
};