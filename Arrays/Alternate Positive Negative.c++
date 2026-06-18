// https://www.geeksforgeeks.org/problems/array-of-alternate-ve-and-ve-nos1401/1&selectedLang=python3

/*
🔴 Rearrange Array by Sign

🧠 Idea:
- Store positive and negative numbers separately.
- Fill the original array alternately:
      positive, negative, positive, negative...
- If one group has remaining elements,
  append them at the end.

🧠 Why use two arrays?
- Makes alternating placement straightforward.
- Preserves the original relative order of positives
  and negatives.

⏱️ TC: O(N)
📦 SC: O(N)

🎯 One line:
"Separate positives and negatives, then merge them alternately."
*/
class Solution {
  public:
    void rearrange(vector<int> &arr) {
        // code here
        vector<int> positives;
        vector<int> negatives;
        
        for(auto x : arr)
        {
            if(x >= 0)
            {
                positives.emplace_back(x);
            }
            else
            {
                negatives.emplace_back(x);
            }
        }
        
        int positiveIndex = 0;
        int negativeIndex = 0;
        int currentIndex= 0;
        
        while( positiveIndex < positives.size() && negativeIndex < negatives.size() )
        {
            if(currentIndex%2 ==0 )
            {
                arr[currentIndex] = positives[positiveIndex];
                currentIndex++;
                positiveIndex++;
            }
            else
            {
                arr[currentIndex] = negatives[negativeIndex];
                currentIndex++;
                negativeIndex++;
            }
        }
        
        while(positiveIndex < positives.size())
        {
            arr[currentIndex] = positives[positiveIndex];
            currentIndex++;
            positiveIndex++;
        }
        while(negativeIndex < negatives.size())
        {
            arr[currentIndex] = negatives[negativeIndex];
            currentIndex++;
            negativeIndex++;
        }
    }
};