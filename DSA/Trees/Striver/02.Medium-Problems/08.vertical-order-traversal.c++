// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> todos;
        // Pushing the root
        todos.push({root, {0, 0}});
        while(!todos.empty()) {
            auto todo = todos.front();
            todos.pop();
            TreeNode* temp = todo.first;
            // x -> vertical
            int x = todo.second.first;  
            // Y -> level
            int y = todo.second.second; 
            nodes[x][y].insert(temp->val);
            if(temp->left){
                todos.push({temp->left,{x-1,y+1}});
            }
            if(temp->right){
                todos.push({temp->right,{x+1,y+1}});
            }
        }
        vector<vector<int>> res;
        for(auto p: nodes){
            vector<int> col;
            for(auto q: p.second){
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            res.push_back(col);
        }
        return res;
    }
};