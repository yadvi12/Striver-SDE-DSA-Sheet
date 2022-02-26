// Link - https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
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
    void createMapping(vector<int>& inorder, map<int, int> &nodeToIndex)
    {
        int size = inorder.size();
        for(int i=0; i<size; i++)
        {
            nodeToIndex[inorder[i]] = i;
        }
    }
    
    TreeNode* solve(vector<int> &preorder, vector<int> &inorder, int &preorderindex, map<int, int> &nodeToIndex, int n, int inorderstart, int inorderend)
    {
        // base case
        if(preorderindex >= n || inorderstart > inorderend)
        {
            return NULL;
        }
        
        int element = preorder[preorderindex++];
        TreeNode* root = new TreeNode(element);
        int position = nodeToIndex[element];
        
        root->left = solve(preorder, inorder, preorderindex, nodeToIndex, n, inorderstart, position -1);
        root->right = solve(preorder, inorder, preorderindex, nodeToIndex, n, position+1, inorderend);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> nodeToIndex;
        createMapping(inorder, nodeToIndex);
        int preorderindex = 0;
        int n = inorder.size();
        TreeNode* ans = solve(preorder, inorder, preorderindex, nodeToIndex, n, 0, n-1);
        return ans;
    }
};
