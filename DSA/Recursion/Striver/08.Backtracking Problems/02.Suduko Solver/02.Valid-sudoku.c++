// https://leetcode.com/problems/valid-sudoku
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][9] = {0}, col[9][9] = {0}, box[9][9] = {0};
        
        for(int i = 0; i < board.size(); ++ i)
            for(int j = 0; j < board[i].size(); ++ j)
                if(board[i][j] != '.')
                {
                    int num = board[i][j] - '0' - 1;
                    // This is to find out of 9 box Which box im at
                    int k = i / 3 * 3 + j / 3;

                    if(row[i][num] || col[j][num] || box[k][num])
                        return false;
                    row[i][num] = col[j][num] = box[k][num] = 1;
                }
        
        return true;
    }
};

// --------------------

// Why  `k = i / 3 * 3 + j / 3` 

// 0  0  0 | 1  1  1 | 2  2  2
// 0  0  0 | 1  1  1 | 2  2  2
// 0  0  0 | 1  1  1 | 2  2  2
// --------+---------+---------
// 3  3  3 | 4  4  4 | 5  5  5
// 3  3  3 | 4  4  4 | 5  5  5
// 3  3  3 | 4  4  4 | 5  5  5
// --------+----------+--------
// 6  6  6 | 7  7  7 | 8  8  8
// 6  6  6 | 7  7  7 | 8  8  8
// 6  6  6 | 7  7  7 | 8  8  8 