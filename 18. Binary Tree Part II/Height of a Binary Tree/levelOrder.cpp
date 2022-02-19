// Link - https://leetcode.com/problems/maximum-depth-of-binary-tree/
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
    int maxDepth(TreeNode* root) {
        
        
        if(!root) 
            return 0;
        
        queue<TreeNode*> q;
        q.push(root);
        int currdepth = 0;
        
        while(!q.empty())
        {
            int size = q.size();

            
            for(int i=0; i<size; i++)
            {
                root = q.front();
                q.pop();
                if(root->left) 
                    q.push(root->left);
                if(root->right) 
                    q.push(root->right);
            }
            currdepth++;
        }
        
        return currdepth;
    }
};
