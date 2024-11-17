// https://leetcode.com/problems/validate-binary-search-tree/

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root,INT_MIN,INT_MAX);
    }
    bool isValidBST(TreeNode* root , int minValue , int maxValue) {
        if(root == NULL)
            return true;
        if(root->val < minValue || root->val > maxValue)
            return false;
        return isValidBST(root->left , minValue , root->val) &&
               isValidBST(root->right , root->val ,maxValue);
    }
};


// Logic:
// Check if root->val is in range of min and max
// Modify min and max accordingly