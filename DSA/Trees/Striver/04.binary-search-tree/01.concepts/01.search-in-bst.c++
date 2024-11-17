// https://leetcode.com/problems/search-in-a-binary-search-tree

// Recursive solution:
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL || root->val == val)
            return root;
        if(root->val > val)
            return searchBST(root->left,val);
        else
            return searchBST(root->right,val);
    }
};

// Iterative solution:

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
       while(root!= NULL and root->val != val){
            if(root->val > val)
                root = root->left;
            else
                root = root->right;
       }
       return root;
    }
};