// https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void helper(int node , vector<int>& ans , vector<int> &visited ,vector<vector<int>>& adj) {
        ans.push_back(node);
        for(int x : adj[node]) {
            if(!visited[x]) {
                    visited[x] = 1; 
                    helper(x , ans , visited , adj);
            }
        }
    }
    
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
       vector<int> ans;
       vector<int> visited(adj.size(),0);
       visited[0] = 1; 
       helper(0 , ans , visited , adj);
       return ans;
    }
};


// TC- O(V+E)
// SC - O(V)