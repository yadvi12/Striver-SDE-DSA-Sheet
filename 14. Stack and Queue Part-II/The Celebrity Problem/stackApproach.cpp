// Link - https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1/#
// Time Complexity - O(N)
// Space Complexity - O(N)

// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution 
{
    private:
    bool knows(vector<vector<int> >& M, int first, int second)
    {
        if(M[first][second] == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        //step 1: create a stack and push all the people
        stack<int> st;
        for(int i=0; i<n; i++)
        {
            st.push(i);
        }
        
        //step 2: compare each element in the stack
        while(st.size() > 1)
        {
            int first = st.top();
            st.pop();
            int second = st.top();
            st.pop();
            if(knows(M,first,second))
            {
                st.push(second);
            }
            else
            {
                st.push(first);
            }
        }
        
        int selected = st.top();
        // cout << selected;
        
        //step 3: check whether the selected element can be the celebrity or not
        
        int rowCount = 0;
        int colCount = 0;
        //all elements of the row of the celebrity should be zero
        for(int i = 0; i < n; i++)
        {
            if(M[i][selected] == 1)
            {
                rowCount++;
            }
        }
        
        //all elements of the column of the celebrity should be 1 except diagonal element
        for(int j = 0; j < n; j++)
        {
            if(M[selected][j] == 0)
            {
                colCount++;
            }
        }
        
        if(rowCount == n-1 && colCount == n)
        {
            return selected;
        }
        return -1;
        
        
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}
  // } Driver Code Ends
