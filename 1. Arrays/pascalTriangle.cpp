// Link - https://leetcode.com/problems/pascals-triangle/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<int> tempAns;
        vector<vector<int>> ans;
        vector<int> prevAns;
        
        tempAns.push_back(1);
        ans.push_back(tempAns);
        for(int i=1; i<numRows; i++)
        {
            if(i==1)
            {
                tempAns.push_back(1);
            }
            
            
            else
            {
               prevAns = tempAns;
               for(int j=1; j<i;j++)
               {
                   tempAns[j]= prevAns[j] + prevAns[j-1];
               }
                tempAns.push_back(1);

            }
            ans.push_back(tempAns);
        }
        
        return ans;
    }
};
