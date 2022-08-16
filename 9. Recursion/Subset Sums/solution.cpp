// Link - https://practice.geeksforgeeks.org/problems/subset-sums2234/1

//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    void solve(int ind, int sum, vector<int> arr, int N, vector<int>& res)
    {
        if(ind == N)
        {
            res.push_back(sum);
            return;
        }
        
        // include
        solve(ind+1, sum+arr[ind], arr, N, res);
        solve(ind+1, sum, arr, N, res);
        
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> res;
        solve(0, 0, arr, N, res);
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
