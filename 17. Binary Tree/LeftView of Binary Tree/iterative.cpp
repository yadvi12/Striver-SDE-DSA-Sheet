// Link - https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1
// Time Complexity - O(N)
// Space Complexity - O(N)

void solve(Node *root, vector<int> &ans)
{
    if(root == NULL)
    {
        return ;
    }
    ans.push_back(root->data);
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty())
    {
        Node* temp = q.front(); 
        q.pop(); 
        
        if(temp == NULL)
        {
            if(!q.empty())
            {
                ans.push_back(q.front()->data);
                q.push(NULL); 
            }
            
        }
        else
        {
            if(temp->left)
            {
                q.push(temp->left); 
            }
            if(temp->right)
            {
                q.push(temp->right); // 7 NULL 5 3
            }
        }
        
    }
}
vector<int> leftView(Node *root)
{
    vector<int> ans;
    
    solve(root, ans);
    return ans;
}
