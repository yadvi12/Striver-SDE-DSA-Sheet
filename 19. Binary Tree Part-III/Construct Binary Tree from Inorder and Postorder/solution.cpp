// Link - https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
// Time Complexity - O(N log N)
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
    void createMapping(vector<int> &inorder, map<int, int> &nodeToIndex)
    {
        int size = inorder.size();
        for(int i = 0; i< size; i++)
        {
            nodeToIndex[inorder[i]] = i;
        }
    }
    
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int &postorderindex, int inorderstart, int inorderend, map<int, int> &nodeToIndex)
    {
        if(postorderindex < 0 || inorderstart > inorderend)
        {
            return NULL;
        }
        
        int element = postorder[postorderindex--];
        TreeNode* root = new TreeNode(element);
        int position = nodeToIndex[element];
        
        root->right = solve(inorder, postorder, postorderindex, position+1, inorderend, nodeToIndex);
        root->left = solve(inorder, postorder, postorderindex, inorderstart, position -1, nodeToIndex);
    
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> nodeToIndex;
        createMapping(inorder, nodeToIndex);
        int n = inorder.size();
        int postorderindex = n-1;
        
        TreeNode* ans = solve(inorder, postorder, postorderindex, 0, n-1, nodeToIndex);
        return ans;
    }
};
