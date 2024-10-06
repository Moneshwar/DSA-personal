// https://leetcode.com/problems/binary-tree-paths/
// This is not a part of striver's Sheet but still feels important

class Solution {
public:
    void dfs(TreeNode* root , vector<string>& res , string temp){
        if(root->left == NULL && root->right == NULL){
            res.push_back(temp);
            return;
        }
        if(root->left != NULL)
            dfs(root->left,res,temp+"->"+to_string(root->left->val));
        if(root->right != NULL)
            dfs(root->right,res,temp+"->" + to_string(root->right->val));
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        string ans = to_string(root->val);
        dfs(root , res ,ans);
        return res;
    }
};