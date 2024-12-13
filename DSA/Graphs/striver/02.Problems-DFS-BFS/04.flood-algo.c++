// https://leetcode.com/problems/flood-fill/description/

class Solution {
private:
    int deltaRow[4] = {-1 , 0 , 1 , 0};
    int deltaCol[4] = {0 , 1, 0, -1};
public:
    void dfs(vector<vector<int>>& ans, int sr, int sc, int initialColor , int color) {
        ans[sr][sc] = color;
        for(int i = 0 ; i < 4 ; i++) {
            int newRow = sr+deltaRow[i];
            int newCol = sc+deltaCol[i];
            if(newRow > -1 && newRow <ans.size() 
                && newCol > -1 && newCol < ans[0].size()
                && ans[newRow][newCol] == initialColor) {
                    dfs(ans , newRow , newCol , initialColor , color);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialColor = image[sr][sc];
        if(initialColor == color)
            return image;
        vector<vector<int>> ans = image;
        dfs(ans , sr , sc , initialColor , color);
        return ans;
    }
};

// Tc - O(N*M)
// Sc - O(N*M)