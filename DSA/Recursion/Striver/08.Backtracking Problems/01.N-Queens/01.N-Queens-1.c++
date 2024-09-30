// Problem : https://leetcode.com/problems/n-queens

// Normal Backtracking:
class Solution {
public:
// Directions to check:
    //       \     
    // __ __ _\ Q
    //        /
    //       /       
    bool isSafeToPlace(int row , int col , int n, vector<string> board) {
        int tempRow = row , tempCol = col;

        // Top diagonal
        while(row >= 0 && col >= 0) {
            if(board[row][col] == 'Q')
                return false;
            row--;
            col--;
        }
        row = tempRow;
        col = tempCol;
        // Bottom diagonal
        while(row<n && col >=0){
            if(board[row][col] == 'Q')
                return false;
            row++;
            col--;
        }
        row = tempRow;
        col = tempCol;
        // Towards left
        while(col >= 0){
            if(board[row][col] == 'Q')
                return false;
            col--;
        }
        return true;

    }
    void helper(int col ,int n, vector<vector<string>> &res , vector<string> board) {
        if(col == n) {
            res.push_back(board);
            return;
        }

        for(int row = 0 ; row < n ; row++) {
            if(isSafeToPlace(row,col,n,board)){
                board[row][col] = 'Q';
                helper(col+1 , n, res , board);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        string s(n,'.');
        vector<string> board(n,s);
        helper(0,n,res,board);
        return res;
    }
};

// -------------------------------------------------

// Optimizing the isSafeToPlace function

class Solution {
public:
    //This solution is just a optimization of the previous brutforce refer: 
    // https://leetcode.com/problems/n-queens/submissions/1386063560/
    // Here we are trying to remove the Time taken by isSafeToPlace function using hashing

    void helper(int col ,int n, vector<vector<string>> &res , vector<string> board,
                vector<bool> topDiagonal , vector<bool> bottomDiagonal , vector<bool> mid) {
        if(col == n) {
            res.push_back(board);
            return;
        }

        for(int row = 0 ; row < n ; row++) {
            // Refere striver's video for this concept of hashing 
            // Not intutive
            if(mid[row] == 0 and topDiagonal[row+col] == 0 and bottomDiagonal[n-1+row-col]==0){
                board[row][col] = 'Q';
                mid[row]=1;
                topDiagonal[row+col]=1;
                bottomDiagonal[n-1+row-col]=1;
                helper(col+1 , n, res , board,topDiagonal,bottomDiagonal,mid);
                board[row][col] = '.';
                mid[row]=0;
                topDiagonal[row+col]=0;
                bottomDiagonal[n-1+row-col]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        string s(n,'.');
        vector<string> board(n,s);
        vector<bool> topDiagonal(2*n-1,0);
        vector<bool> bottomDiagonal(2*n-1,0);
        vector<bool> mid(n,0);
        helper(0,n,res,board,topDiagonal,bottomDiagonal,mid);
        return res;
    }
};
