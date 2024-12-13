// https://leetcode.com/problems/rotting-oranges/submissions/1477266909/

class Solution {
private:
    int drow[4]={-1,0,0,1};
    int dcol[4]={0,-1,1,0};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh=0;
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                }
                else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        if(fresh==0){
            return 0;
        }
        int ans=0;

        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int time=q.front().second;
            ans = time;
            q.pop();
            //check for all the adjacent elements
            for(int i=0;i<4;i++){
                int newRow=row+drow[i];
                int newCol=col+dcol[i];
                if(newRow>=0 && newRow<m && newCol>=0 && newCol<n 
                    && grid[newRow][newCol]==1) {

                    q.push({{newRow,newCol},time+1});
                    grid[newRow][newCol]=2;
                    fresh--;
                }
            }
        }
        if(fresh>0){
            return -1;
        }
        return ans;
    }
};


// Tc - O(N*M)
// Sc - O(N*M)