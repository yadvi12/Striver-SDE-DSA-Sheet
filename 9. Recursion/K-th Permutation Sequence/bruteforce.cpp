// Link - https://leetcode.com/problems/permutation-sequence/

class Solution {
public:
    void helper(int n, vector<string>& ans, string& res , int ind)
    {
        if(ind == n-1)
        {
            ans.push_back(res);
            return;
        }
        
        for(int i=ind; i<n; i++)
        {
            swap(res[i], res[ind]);
            helper(n, ans, res, ind+1);
            swap(res[i], res[ind]);
        }
    }
    string getPermutation(int n, int k) {
        string res;
        vector<string> ans;
        
        for(int i=1; i<=n; i++)
        {
            res += to_string(i);
        }
        helper(n, ans, res, 0);
        sort(ans.begin(), ans.end());
        return ans[k-1];
    }
};
