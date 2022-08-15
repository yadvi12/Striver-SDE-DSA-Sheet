// Link - https://leetcode.com/problems/permutations/

class Solution {
public:
    void helper(vector<int>& nums, int index, vector<vector<int>>& res)
    {
        if(index == nums.size()-1)
        {
            res.push_back(nums);
            return;
        }
        
        for(int i = index; i < nums.size(); i++)
        {
            swap(nums[i], nums[index]);
            helper(nums, index+1, res);
            swap(nums[i], nums[index]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> res;
        helper(nums, 0, res);
        return res;
    }
};
