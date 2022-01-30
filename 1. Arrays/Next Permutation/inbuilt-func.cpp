// Link - https://leetcode.com/problems/next-permutation/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        nums.push_back(next_permutation(nums.begin(),nums.end()));
        nums.pop_back();
    }   
        
};

