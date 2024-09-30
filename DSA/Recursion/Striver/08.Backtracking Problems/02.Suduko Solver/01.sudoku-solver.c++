https://leetcode.com/problems/sudoku-solver/
class Solution {
public:
    bool helper(vector<vector<char>>& board) {
        for(int i = 0 ; i < 9 ; i++) {
            for(int j = 0 ; j < 9 ; j++) {
                if(board[i][j] == '.') {
                    for(int k = 1 ; k <= 9 ; k++){
                        if(isValid(board , i , j , k+'0')) {
                            board[i][j] = k +'0';
                            if(helper(board)) 
                                return true;
                            else
                                board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    bool isValid(vector<vector<char>> &board, int row, int col, char k)
    {
        for (int i = 0; i < 9; i++)
        {
            if (board[row][i] == k)
                return false;

            if (board[i][col] == k)
                return false;
            // This is we need to think for a while not so intituve
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == k)
                return false;
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        helper(board);
    }
};