// https://bit.ly/3qnaLjq

#include <bits/stdc++.h>
void helper(vector<int> &arr, int n, int index, vector<int> &curr, vector<vector<int>> &res)
{
    if(index == n)
    {
        vector<int> newcurr = curr;
        sort(newcurr.begin(), newcurr.end());
        res.push_back(newcurr);
        return;
    }
    
    
    curr.push_back(arr[index]);
    helper(arr, n, index+1, curr , res);

    curr.pop_back();
    helper(arr, n, index+1, curr , res);
}

vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    vector<vector<int>> res;
    vector<int> curr;
    helper(arr, n, 0, curr, res);
    sort( res.begin(), res.end() );
    res.erase( unique( res.begin(), res.end() ), res.end() );
    return res;
}
