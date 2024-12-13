// https://www.geeksforgeeks.org/problems/find-the-number-of-islands/

class Solution {
  public:
    // Function to find the number of islands.
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

                        // Note: Need to check a easier way to do this

                        // insert all eight directions which is land
                        int newI = top.first;
                        int newJ = top.second;
                        // Top
                        if(newI - 1 > -1) {
                            if(newJ - 1 > -1 && !visited[newI - 1][newJ - 1] && grid[newI - 1][newJ - 1] == '1') {
                                visited[newI - 1][newJ - 1] = 1;
                                q.push({newI - 1 ,newJ - 1});
                            }
                            if(!visited[newI - 1][newJ] && grid[newI - 1][newJ] == '1') {
                                visited[newI - 1][newJ] = 1;
                                q.push({newI - 1 ,newJ});
                            }
                            if(newJ + 1 < n && !visited[newI - 1][newJ +1] && grid[newI - 1][newJ +1] == '1') {
                                visited[newI - 1][newJ + 1] = 1;
                                q.push({newI - 1 ,newJ + 1});
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
                            if(newJ - 1 > -1 && !visited[newI + 1][newJ-1] && grid[newI + 1][newJ-1] == '1') {
                                visited[newI+1][newJ - 1] = 1;
                                q.push({newI+1,newJ - 1});
                            }
                            if(!visited[newI + 1][newJ] && grid[newI + 1][newJ] == '1'){
                                visited[newI+1][newJ] = 1;
                                q.push({newI+1,newJ });
                            }
                            if(newJ + 1 < n && !visited[newI + 1][newJ + 1] && grid[newI + 1][newJ + 1] == '1') {
                                visited[newI+1][newJ + 1] = 1;
                                q.push({newI+1,newJ + 1});
                            }
                        }
                    }
                }
            }
        }
        return res;
    }
};

// TC- O(N^2)
// SC- O(N^2)
