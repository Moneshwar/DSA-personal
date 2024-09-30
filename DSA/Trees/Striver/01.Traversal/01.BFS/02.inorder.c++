// https://leetcode.com/problems/binary-tree-inorder-traversal/
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
    void inorder(vector<int>& ans, TreeNode* node) {
        if(node == NULL){
            return;
        }
        inorder(ans,node->left);
        ans.push_back(node->val);
        inorder(ans,node->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        // Inorder -> LEFT , ROOT , RIGHT
        vector<int> ans;
        inorder(ans,root);
        return ans;
    }
};

// TC- O(N)
// SC - O(N)