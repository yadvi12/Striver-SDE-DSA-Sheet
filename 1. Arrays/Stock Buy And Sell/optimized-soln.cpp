// Link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Time Complexity - O(N)
// Space Complexity - O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minSoFar = prices[0];
        int maxProfit = 0;
        for(int i = 0; i<n; i++){
            minSoFar = min(minSoFar,prices[i]);
            int profit = prices[i] - minSoFar;
            if(profit > maxProfit){
                maxProfit = profit;
            }
        }
        return maxProfit;
    }
};
