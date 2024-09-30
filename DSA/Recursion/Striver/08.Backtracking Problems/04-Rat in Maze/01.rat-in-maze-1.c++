// https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

class Solution {
  public:
    vector<pair<int,int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};
    string directionString = "UDLR";
    
    bool isValid(int i , int j ,vector<vector<bool>> &visited , vector<vector<int>> &mat) {
        // Size validation
        if(i >= 0 && i < mat.size() && j>=0 && j < mat[0].size()) {
            if(visited[i][j] == 0 && mat[i][j] == 1){
                return true;
            }
        }
        return false;
    }
    
    void helper(int i,int j,string ans,vector<string> &res,vector<vector<int>> &mat,
                vector<vector<bool>> &visited) {
        
        if(i == mat.size()-1 and j == mat[0].size()-1){
            res.push_back(ans);
        }
        for(int index = 0 ; index<directionString.length() ;index++) {
            int nextI = i+directions[index].first;
            int nextJ = j+directions[index].second;
            if(isValid(nextI , nextJ , visited , mat)) {
               visited[i][j] = 1;
               helper(nextI,nextJ,ans+directionString[index],res,mat,visited);
               visited[i][j] = 0;
            }
        }
    }
    
    vector<string> findPath(vector<vector<int>> &mat) {
       vector<vector<bool>> visited(mat.size(),vector<bool>(mat[0].size(),false));
       vector<string> res;
       if(mat[0][0] == 1)
            helper(0,0,"",res,mat,visited);
       return res;
    }
};
