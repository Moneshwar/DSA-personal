// https://leetcode.com/problems/symmetric-tree/
// This is very similar to is given two trees are identical
// Here we consider the the same tree as two different trees.

class Solution {
public:
    bool isSymmetricHelper(TreeNode* p , TreeNode* q){
        if(p == NULL || q == NULL)
            return (p == q);
        return (
            p->val == q->val &&
            isSymmetricHelper(p->left , q->right) &&
            isSymmetricHelper(p->right , q->left)
        );
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        return isSymmetricHelper(root->left , root ->right);
    }
};