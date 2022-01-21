// Link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Time Complexity - O(n), Space Complexity - O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int diff = 0;
        int maximum= -9999999999;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                diff = prices[j] - prices[i];
                if(diff > maximum){
                    maximum = diff;
                }
            }
        }
        if(maximum > 0){
            return maximum;
        }
        else{
            return 0;
        }
    }
};
