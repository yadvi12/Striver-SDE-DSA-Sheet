// Link - https://leetcode.com/problems/next-permutation/
// Time Complexity - O(N)
// Space Complexity - O(1)

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
                    int index1 = -1, index2 = -1;
                    for(int i = 0; i<n-1; i++)
                    {
                        if(nums[i] < nums[i+1])
                        {
                            index1 = i;
                        }
                    }
                    
                    for(int j=n-1; j>index1; j--)
                    {
                        if(nums[j] > nums[index1])
                        {
                            index2 = j;
                            break;
                        }
                    }
                    
                    swap(nums[index1], nums[index2]);
                    reverse(nums.begin() + index1 +1, nums.end());
                }
    }   
        
};

