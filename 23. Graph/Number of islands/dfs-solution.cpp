// Link - https://leetcode.com/problems/number-of-islands/

class Solution {
private:
    void dfs(int i, int j, vector<vector<int>>& visited, vector<vector<char>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        visited[i][j] = 1;
        
        if(i-1 >= 0 && i-1 < n && j >=0 && j < m && grid[i-1][j] == '1' && !visited[i-1][j])
        {
            dfs(i-1, j, visited, grid);
        }
        if(i >= 0 && i < n && j+1 >=0 && j+1 < m && grid[i][j+1] == '1' && !visited[i][j+1])
        {
            dfs(i, j+1, visited, grid);
        }
        if(i+1 >= 0 && i+1 < n && j >=0 && j < m && grid[i+1][j] == '1' && !visited[i+1][j])
        {
            dfs(i+1, j, visited, grid);
        }
        if(i >= 0 && i < n && j-1 >=0 && j-1 < m && grid[i][j-1] == '1' && !visited[i][j-1])
        {
            dfs(i, j-1, visited, grid);
        }
        
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(!visited[i][j] && grid[i][j] != '0')
                {
                    count++;
                    dfs(i, j, visited, grid);
                }
            }
        }
        return count;
    }
};
