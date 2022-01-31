// Link - https://leetcode.com/problems/find-the-duplicate-number/
// Time Complexity - O(NlogN) + O(N)  -> Time Complexity Exceeded
// Space Complexity - O(1)

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0; i<n-1; i++)
        {
            if(nums[i] == nums[i+1])
            {
                return nums[i];
            }
        }
        return -1;
    }
};
