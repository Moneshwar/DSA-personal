// https://leetcode.com/problems/number-of-islands

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m , vector<int>(n,0));
        queue<pair<int,int>> q;
        for(int i = 0 ; i < m ; i++) {
            for(int j = 0 ; j < n ; j++) {
                if(!visited[i][j] && grid[i][j] == '1') {
                    res++;
                    q.push({i,j});
                    visited[i][j] = 1;
                    while(!q.empty()) {
                        pair<int,int> top = q.front();
                        q.pop();

                        // insert all fout directions which is land
                        int newI = top.first;
                        int newJ = top.second;
                        // Top
                        if(newI - 1 > -1) {
                            if(!visited[newI - 1][newJ] && grid[newI - 1][newJ] == '1') {
                                visited[newI - 1][newJ] = 1;
                                q.push({newI - 1 ,newJ});
                            }
                        }

                        // Same level
                        if(newJ - 1 > -1 && !visited[newI][newJ - 1] && grid[newI][newJ - 1] == '1') {
                            visited[newI][newJ - 1] = 1;
                            q.push({newI,newJ - 1});
                        }
                        if(newJ + 1 < n && !visited[newI][newJ + 1] && grid[newI][newJ + 1] == '1') {
                            visited[newI][newJ + 1] = 1;
                            q.push({newI,newJ + 1});
                        }

                        // Bottom
                        if(newI + 1 < m) {
                            if(!visited[newI + 1][newJ] && grid[newI + 1][newJ] == '1'){
                                visited[newI+1][newJ] = 1;
                                q.push({newI+1,newJ });
                            }
                        }
                    }
                }
            }
        }
        return res;
    }
};

// Same as previous just removed diagonal check