// https://leetcode.com/problems/count-complete-tree-nodes/solutions/

// This is a easier version in O(N) time and O(N) space

class Solution {
public:
// This will work for all trees.
    void dfs(TreeNode* root , int& res) {
        if(root == NULL)
            return;
        res++;
        dfs(root->left , res);
        dfs(root->right,res);
    }
    int countNodes(TreeNode* root) {
        int res = 0;
        dfs(root,res);
        return res;
    }
};

