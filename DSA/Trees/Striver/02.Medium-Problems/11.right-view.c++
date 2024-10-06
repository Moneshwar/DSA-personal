// https://leetcode.com/problems/binary-tree-right-side-view

class Solution {
public:
    void dfs(TreeNode* root , vector<int>& ans , int level) {
        if(root == NULL)
            return;
        if(level == ans.size())
            ans.push_back(root->val);
        // To get right view
        dfs(root->right , ans , level+1);
        dfs(root->left , ans , level+1);

    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        // ROOT , RIGHT , LEFT -> We need to travel
        dfs(root , ans , 0);
        return ans;
    }
};