// Link - https://bit.ly/3Gs6wZu
// Time Complexity - O(N)
// Space Complexity - O(1)

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	pair<int, int> ans;
    vector<long long> v(n+1,0);
    for(long long i=0; i<n; i++)
    {
        v[arr[i]] += 1;
    }
	
    for(long long i=0; i<=n; i++)
    {
        if(v[i] == 0)
        {
            ans.first = i;
        }
        
        if(v[i] == 2)
        {
            ans.second = i;
        }
    }
    return ans;
}
