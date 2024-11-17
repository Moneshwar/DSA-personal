// https://leetcode.com/problems/delete-node-in-a-bst/description/

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL)
            return root;
        TreeNode* rootClone = root;
        if(root->val == key){
            return helper(root);
        }
        while(root != NULL) {
            if(root->val > key) {
                if(root->left != NULL and root->left->val == key){
                    root->left = helper(root->left);
                    break;
                }
                else
                    root = root->left;
            }
            else {
                if(root->right != NULL and root->right->val == key) {
                    root->right = helper(root->right);
                    break;
                }
                else
                    root = root->right;
            }
        }
        return rootClone;
    }
    TreeNode* helper(TreeNode* root) {
        if(root->left == NULL)
            return root->right;
        if(root->right == NULL)
            return root->left;
        TreeNode* rightChildren = root->right;
        TreeNode* lastChild = getLastRightChild(root->left);
        lastChild->right = rightChildren;
        return root->left;
    }
    TreeNode* getLastRightChild(TreeNode* root) {
        if(root->right == NULL)
            return root;
        return getLastRightChild(root->right);
    }
};