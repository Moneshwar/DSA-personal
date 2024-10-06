// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
// I can understand this solution but can't arrive at it 

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || p == root || q == root)
            return root;
        TreeNode* left = lowestCommonAncestor(root->left , p , q);
        TreeNode* right = lowestCommonAncestor(root->right , p , q);
        if(left == NULL)
            return right;
        if(right == NULL)
            return left;
        // Both are not NULL , then this is our first answer we need to pass it.
        return root;
    }
    