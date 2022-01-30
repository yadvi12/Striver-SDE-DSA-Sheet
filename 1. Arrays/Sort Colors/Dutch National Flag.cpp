// Link - https://leetcode.com/problems/sort-colors/
// Time Complexity = O(N) -> Running the loop one time
// Space Complexity = O(1)

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        
                int sorted = 0;
                for(int i=0; i<n-1; i++)
                {
                    if(nums[i] < nums[i+1])
                    {
                        sorted = 1;
                        break;
                    }
                }
                if(sorted == 0)
                {
                    reverse(nums.begin(),nums.end());
                }
                else
                {
                    
                }
    }   
        
};

