// Link - https://leetcode.com/problems/diameter-of-binary-tree/
// Time Complexity - O(N^2)
// Space Complexity - O(h), h is the height of the binary tree

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
    int height(TreeNode* root) {
    if(root == NULL)
    {
        return 0;
    }
    
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    
    return max(leftHeight, rightHeight) + 1;
}

public:
    int diameterOfBinaryTree(TreeNode* root) {
            if(root == NULL)
            {
                return 0;
            }
            int op1 = diameterOfBinaryTree(root->left);
            // cout << "op1 " << op1 << endl;
            int op2 = diameterOfBinaryTree(root->right);
            // cout << "op2 " << op2 << endl;
            int op3 = height(root->left) + height(root->right);
            // cout << "op3 " << op3 << endl;
            int ans = max(op1, max(op2, op3));
            return ans; 
    }
};
