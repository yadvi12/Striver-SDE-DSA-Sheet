// Link - https://www.interviewbit.com/problems/repeat-and-missing-number-array/
// Time Complexity - O(N)
// Space Complexity - O(1)

vector<int> Solution::repeatedNumber(const vector<int> &A) {
    vector<int> ans;
    long long int n = A.size();
    long long int missing = 0;
    long long int repeating = 0;
	  long long int diff1 = n*(n+1)/2;
    long long int diff2 = n*(n+1)*((2*n)+1)/6;
    for(long long int i=0; i<n; i++)
    {
        diff1 -= (long long int)A[i];
        diff2 -= (long long int)A[i] * (long long int)A[i];
    }
    
    missing = ((diff2/diff1) + diff1)/2;
    repeating = missing - diff1;
    ans.push_back(repeating);
    ans.push_back(missing);
    return ans;
}
