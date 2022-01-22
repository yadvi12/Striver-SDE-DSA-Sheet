// Link - https://leetcode.com/problems/set-matrix-zeroes/
// Time Complexity - O((m*n) + (m+n))
// Space Complexity - O(1)

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(matrix[i][j]==0){
                   //i=1,j=1
                    
                    //k=0 to 2
                    for(int k = 0; k <row; k++){
                        if(matrix[k][j]!=0){
                            matrix[k][j]=9999999;
                        }
                    }
                    
                    
                    //k=0 to 2
                    for(int k=0; k<col; k++){
                        if(matrix[i][k]!=0){
                            matrix[i][k]=9999999;
                        }
                    }
                }
            }
        }
        
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(matrix[i][j]==9999999){
                    matrix[i][j]=0;
                }
            }
        }
    }
};


