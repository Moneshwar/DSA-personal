// https://leetcode.com/problems/n-queens-ii
// Same question , only the way we store answer is different
class Solution {
public:
     void helper(int col ,int n, int &res , vector<bool> topDiagonal , 
                    vector<bool> bottomDiagonal , vector<bool> mid) {
        if(col == n) {
            // res.push_back(board);
            res++;
            return;
        }

        for(int row = 0 ; row < n ; row++) {
            if(mid[row] == 0 and topDiagonal[row+col] == 0 and bottomDiagonal[n-1+row-col]==0){
                // board[row][col] = 'Q';
                mid[row]=1;
                topDiagonal[row+col]=1;
                bottomDiagonal[n-1+row-col]=1;
                helper(col+1 , n, res ,topDiagonal,bottomDiagonal,mid);
                // board[row][col] = '.';
                mid[row]=0;
                topDiagonal[row+col]=0;
                bottomDiagonal[n-1+row-col]=0;
            }
        }
    }
    int totalNQueens(int n) {
        // vector<vector<string>> res;
        int res = 0;
        // string s(n,'.');
        // vector<string> board(n,s);
        vector<bool> topDiagonal(2*n-1,0);
        vector<bool> bottomDiagonal(2*n-1,0);
        vector<bool> mid(n,0);
        helper(0,n,res,topDiagonal,bottomDiagonal,mid);
        return res;
    }
};