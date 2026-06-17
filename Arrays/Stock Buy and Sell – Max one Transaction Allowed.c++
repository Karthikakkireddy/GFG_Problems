// https://www.geeksforgeeks.org/problems/buy-stock-2/1


/*
🔴 Best Time to Buy and Sell Stock (Brute Force)

🧠 Idea:
- Treat every day as a potential buying day.
- For each buying day, check every future day as a selling day.
- Compute the profit:
      sellPrice - buyPrice
- Keep track of the maximum profit found.

🧠 Example:
prices = [7,1,5,3,6,4]

Buy at 1:
    Sell at 5 → profit = 4
    Sell at 3 → profit = 2
    Sell at 6 → profit = 5 ✅
    Sell at 4 → profit = 3

Maximum Profit = 5

⚠️ Why j starts from i+1?
- Stock must be bought before it is sold.
- Same day or previous days cannot be used for selling.

⏱️ TC: O(N²)
📦 SC: O(1)

🎯 One line:
"Try every buy day with every future sell day and keep the maximum profit."
*/
class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        // code here
        int maxProfit = 0 ;
        int n = prices.size();
        for(int i=0 ; i< n ; i++)
        {
            int currentStock = prices[i]; 
            
            for(int j= i+1 ; j< n ;j++)
            {
                int profit = prices[j] - prices[i];
                
                maxProfit = max(profit, maxProfit);
            }
        }
        
        return maxProfit;
    }
};


/*
🔴 Best Time to Buy and Sell Stock (Right-to-Left Traversal)

🧠 Idea:
- Traverse from right to left.
- Maintain the highest stock price seen so far.
- Treat the current day as the buying day.
- Profit if bought today:

      highestStock - prices[i]

- Keep track of the maximum profit.

🧠 Example:
prices = [7,1,5,3,6,4]

Start from right:

highestStock = 4

6:
    highestStock = 6
    profit = 0

3:
    profit = 6 - 3 = 3

5:
    profit = 6 - 5 = 1

1:
    profit = 6 - 1 = 5 ✅

7:
    profit = 7 - 7 = 0

Answer = 5

🧠 Why does this work?
- While moving right to left, highestStock always stores
  the best possible selling price available in the future.
- Therefore, for each day, we can instantly compute the
  best profit if we buy on that day.

⏱️ TC: O(N)
📦 SC: O(1)

🎯 One line:
"Keep the maximum future selling price and calculate profit for each possible buying day."
*/
class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        // code here
        int maxProfit = 0 ; 
        int n = prices.size();
        int highestStock = 0;
        
        for(int i = n-1 ; i>=0 ; i--)
        {
            highestStock = max(highestStock , prices[i]);
            
            maxProfit = max(maxProfit, highestStock - prices[i] );
        }
        return maxProfit;
    }
};


/*
🔴 Best Time to Buy and Sell Stock (Optimal)

🧠 Idea:
- Traverse from left to right.
- Keep track of the minimum stock price seen so far.
- Treat the current day as the selling day.
- Profit if sold today:

      prices[i] - minimumStockTillDate

- Keep track of the maximum profit.

🧠 Example:
prices = [7,1,5,3,6,4]

7:
    min = 7
    profit = 0

1:
    min = 1
    profit = 0

5:
    profit = 5 - 1 = 4

3:
    profit = 3 - 1 = 2

6:
    profit = 6 - 1 = 5 ✅

4:
    profit = 4 - 1 = 3

Answer = 5

🧠 Why does this work?
- minimumStockTillDate stores the best buying price
  available before or on the current day.
- For every day, we instantly compute the best profit
  if we sell on that day.

⏱️ TC: O(N)
📦 SC: O(1)

🎯 One line:
"Keep the minimum buying price so far and calculate profit for each possible selling day."
*/
class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        // code here
        int maxProfit = 0 ; 
        int n = prices.size();
        int minimumStockTillDate = INT_MAX;
        
        for(int i = 0 ; i<n ; i++)
        {
            minimumStockTillDate = min(minimumStockTillDate , prices[i]);
            
            maxProfit = max(maxProfit, prices[i] - minimumStockTillDate );
        }
        return maxProfit;
    }
};
