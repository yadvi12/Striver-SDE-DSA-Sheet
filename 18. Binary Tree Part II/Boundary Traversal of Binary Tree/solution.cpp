// Link - https://bit.ly/3GxQ6yH
// Time Complexity - O(N)
// Space Complexity - O(Height of the Tree)

/************************************************************

    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
void traverseLeft(TreeNode<int>* root, vector<int> &ans)
{
    if(root == NULL || (root->left == NULL && root->right == NULL))
    {
        return ;
    }
    
    ans.push_back(root->data);
    if(root->left)
    {
        traverseLeft(root->left, ans);
    }
    else
    {
        traverseLeft(root->right, ans);
    }
}

void traverseLeafNodes(TreeNode<int>* root, vector<int> &ans)
{
    if(root == NULL)
    {
        return;
    }
    
    if(root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
        return;
    }
    traverseLeafNodes(root->left, ans);
    traverseLeafNodes(root->right, ans);
}

void traverseRight(TreeNode<int>* root, vector<int> &ans)
{
    if(root == NULL || (root->left == NULL && root->right == NULL))
    {
        return ;
    }
    if(root->right)
    {
         traverseRight(root->right, ans);
    }
    else
    {
        traverseRight(root->left, ans);
    }
   ans.push_back(root->data);
}

vector<int> traverseBoundary(TreeNode<int>* root){
    vector<int> ans;
    if(root == NULL)
    {
        return ans;
    }
    ans.push_back(root->data);
    
    if(root->left == NULL && root->right == NULL)
			return ans;
    traverseLeft(root->left, ans);
    traverseLeafNodes(root, ans);
    traverseRight(root->right, ans);
    return ans;
    
}
