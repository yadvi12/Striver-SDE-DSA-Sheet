// Link - https://leetcode.com/problems/maximum-subarray/
// Time Complexity - O(n^2)
// Space Complexity - O(1)

class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        
        int maxSum = INT_MIN;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            int sum = 0;
            for(int j = i; j < n; j++)
            {
                sum += nums[j];
                if(sum > maxSum)
                {
                    maxSum = sum;
                }
            }
        }
        
        return maxSum;
    }
};
