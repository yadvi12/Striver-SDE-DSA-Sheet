// Link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Time Complexity - O(N)
// Space Complexity - O(N)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maximum = prices[n-1];
        vector<int> maxAns(n);
        int diff = 0;
        int maxDiff = 0;
        for(int i = n-1; i>=0; i--){
            maximum = max(maximum, prices[i]);
            maxAns.push_back(maximum);
        }
        
        reverse(maxAns.begin(), maxAns.end());
        
        for(int i = 0; i<n; i++){
            diff = maxAns[i] - prices[i];
            if(diff > maxDiff){
                maxDiff = diff;
            }
        }
        return maxDiff;
    }
};
