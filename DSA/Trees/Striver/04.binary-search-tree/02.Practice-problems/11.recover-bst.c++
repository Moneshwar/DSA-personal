// https://leetcode.com/problems/recover-binary-search-tree/

class Solution {
public:
    TreeNode* prev ;
    TreeNode* first;
    TreeNode* last;
    void inorder(TreeNode* root) {
        if(root == NULL)
            return;
        inorder(root->left);
        if(root->val < prev->val) {
            if(first == NULL) 
                first = prev;
            last = root;
        }
        prev = root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        first = last = NULL;
        prev = new TreeNode(INT_MIN);
        inorder(root);
        if(first && last)
            swap(first->val , last->val);
    }
};


// Little tickey to understand
// Watch striver's video will understand it.