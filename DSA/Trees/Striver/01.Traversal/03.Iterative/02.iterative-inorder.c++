// https://leetcode.com/problems/binary-tree-inorder-traversal
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
    vector<int> inorderTraversal(TreeNode* root) {
        // Inorder -> LEFT , ROOT , RIGHT
        vector<int> ans;
        TreeNode* node = root;
        stack<TreeNode*> st;
        while(true){
            if(node == NULL){
                if(st.empty())
                    break;
                node = st.top();
                st.pop();
                ans.push_back(node->val);
                node = node->right;
            }
            else{
                st.push(node);
                node = node->left;
            }
        }
        return ans;
    }
};

// We directly convert the recustion solution into stack based solution bit trickey.