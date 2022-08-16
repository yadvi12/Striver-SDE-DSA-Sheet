// Link - https://bit.ly/3fmwP7t

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    bool isSafe(vector<vector<bool>> visited, vector<vector<int>>& m, int i, int j, int n)
    {
        if((i >=0 && i < n) && (j >=0 && j <n) && visited[i][j] == 0 && m[i][j] == 1) return true;
        return false;
    }
    void helper(vector<vector<int>>& m, int n, int i, int j, string curr, vector<string>& res, vector<vector<bool>> visited)
    {
        // base case
        if(i == n-1 && j == n-1)
        {
            res.push_back(curr);
            return;
        }
    
        // recursive calls
        visited[i][j] = true;
        if(isSafe(visited, m, i+1, j, n)) helper(m, n, i+1, j, curr + 'D', res, visited);
        if(isSafe(visited, m, i-1, j, n)) helper(m, n, i-1, j, curr + 'U', res, visited);
        if(isSafe(visited, m, i, j-1, n)) helper(m, n, i, j-1, curr + 'L', res, visited);
        if(isSafe(visited, m, i, j+1, n)) helper(m, n, i, j+1, curr + 'R', res, visited);
        
        // backtracking
        visited[i][j] = false;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> res;
        vector<vector<bool>> visited(n, vector<bool>(n, 0));
        if(m[0][0] == 0) return res;
        helper(m, n, 0, 0, "", res, visited);
        return res;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
