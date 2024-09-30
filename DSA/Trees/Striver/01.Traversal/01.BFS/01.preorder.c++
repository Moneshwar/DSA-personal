// https://leetcode.com/problems/binary-tree-preorder-traversal/

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
    void preorder(vector<int>& ans, TreeNode* node) {
        if(node == NULL){
            return;
        }
        ans.push_back(node->val);
        preorder(ans,node->left);
        preorder(ans,node->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        // Preorder -> ROOT , LEFT , RIGHT
        vector<int> ans;
        preorder(ans,root);
        return ans;
        
    }
};

// TC- O(N)
// SC - O(N)