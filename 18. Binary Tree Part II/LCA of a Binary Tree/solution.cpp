// Link - https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
// Time Complexity - O(N)
// Space Complexity - O(height), O(N) in case of skew trees

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
        {
            return NULL;
        }
        if(root->val == p->val || root->val == q->val)
        {
            return root;
        }
        TreeNode* leftans = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightans = lowestCommonAncestor(root->right, p, q);
        
        if(leftans != NULL && rightans != NULL)
        {
            return root;
        }
        else if(leftans != NULL && rightans == NULL)
        {
            return leftans;
        }
        else if(leftans == NULL && rightans != NULL)
        {
            return rightans;
        }
        else if(leftans == NULL && rightans == NULL)
        {
            return NULL;
        }
        
        return root;
        
    }
};
