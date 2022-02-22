// Link - https://leetcode.com/problems/binary-tree-level-order-traversal/
// Time Complexity - O(N)
// Space Complexity - O(N)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> finalans;
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
        if(root == NULL)
        {
            return finalans;
        }
        
        while(!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();
          
            if(temp == NULL)
            {
                finalans.push_back(ans);
                if(!q.empty())
                {
                    ans = {};
                    q.push(NULL);
                }
            }
            else
            {
                ans.push_back(temp->val);
                if(temp->left)
                {
                    q.push(temp->left);
                }
                if(temp->right)
                {
                    q.push(temp->right);
                }
            }
        }
        return finalans;
    }
};
