// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
            return root;
        int val = root->val;
        if(val > p->val and val > q->val)
            return lowestCommonAncestor(root->left , p , q);
        if(val < p->val and val < q->val)
            return lowestCommonAncestor(root->right , p , q);
        return root;
    }
};
