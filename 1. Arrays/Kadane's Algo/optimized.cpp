// Link - https://leetcode.com/problems/maximum-subarray/
// Time Complexity - O(N)
// Space Complexity - O(1)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxiSum = nums[0];
        int sum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            maxiSum = max(sum, maxiSum);
            if(sum < 0)
            {
                sum = 0;
            }
        }
        return maxiSum;
    }
};
