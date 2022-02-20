// Link - https://leetcode.com/problems/balanced-binary-tree/
// Time Complexity - O(N^2)
// Space Complexity - O(h), h is the height of the tree

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
private:
    int height(TreeNode* root)
    {
        if(root == NULL)
        {
            return 0;
        }
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        
        
        return max(leftHeight, rightHeight) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
        {
            return true;
        }
        bool leftBalanced = isBalanced(root->left);
        bool rightBalanced = isBalanced(root->right);
        bool currBalanced = abs(height(root->left) - height(root->right)) <= 1;
        
        if(leftBalanced && rightBalanced && currBalanced)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
