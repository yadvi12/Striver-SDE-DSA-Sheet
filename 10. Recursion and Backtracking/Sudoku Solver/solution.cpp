// Link - https://leetcode.com/problems/sudoku-solver/

class Solution {
public:
    bool isSafe(int i, int j, vector<vector<char>>& board, int val)
    {
        for(int k = 0; k < 9; k++)
        {
            if((board[i][k] == val) || (board[k][j] == val) || (board[3 * (i/3) + k/3][3 * (j/3) + k%3] == val)) return false;
        }
        return true;
    }
    
    bool helper(vector<vector<char>>& board)
    {
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] == '.')
                {
                    for(int val = '1'; val <= '9'; val++)
                    {
                        if(isSafe(i, j, board, val))
                        {
                            board[i][j] = val;
                            bool safeAhead = helper(board);
                            if(safeAhead) return true;
                            else board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        helper(board);
    }
};
