// https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

class Solution {
  public:
    vector<int> bfsOfGraph(vector<vector<int>> &adj) {
        vector<int> res;
        int visited[adj.size()] = {0};
        queue<int> q;
        q.push(0);
        visited[0]=1;
        
        while(!q.empty()) {
            int node = q.front();
            res.push_back(node);
            q.pop();
            for(int x : adj[node]) {
                if(!visited[x]) {
                    q.push(x);
                    visited[x]=1;
                }
            }
        }
        return res;
    }
};

// TC: O(V+E)
// SC: O(V)