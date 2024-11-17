// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        // We need to pass i by reference only so that 
        // Same number is not added two times
        int i = 0;
        return generateTree(preorder , i , INT_MAX);
    }
    TreeNode* generateTree(vector<int>& preorder , int &i , int range) {
        if(i == preorder.size() || preorder[i] > range)
            return NULL;
        TreeNode* root = new TreeNode(preorder[i]);
        i++;
        root->left = generateTree(preorder , i , root->val);
        root->right = generateTree(preorder , i , range);
        return root;
    }
};