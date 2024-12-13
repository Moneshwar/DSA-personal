// https://leetcode.com/problems/number-of-provinces/

class Solution {
private:
    void dfs(int node , vector<int>& visited , vector<vector<int>>& adj) {
        for(int x : adj[node]) {
            if(!visited[x]) {
                visited[x] = 1;
                dfs(x,visited,adj);
            }
        }
    }
    // This one we may not need to do it all time
    vector<vector<int>> getAdjacencyList(vector<vector<int>>& isConnected) {
        vector<vector<int>> adjList(isConnected.size());
        for(int i =0 ; i< isConnected.size() ; i++) {
            for(int j = 0 ; j < isConnected.size() ; j++) {
                if(isConnected[i][j] == 1 && i != j) {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        return adjList;
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<vector<int>> adjList = getAdjacencyList(isConnected);
        int res = 0;
        vector<int> visited(isConnected.size(),0);
        for(int i = 0 ; i<adjList.size();i++) {
            if(!visited[i]) {
                res++;
                visited[i] = 1;
                dfs(i,visited,adjList);
            }
        }
        return res;
    }
};

// Note here i have converted into adjacency list to make things easier
// Tc- O(V+E)
// SC- O(V)