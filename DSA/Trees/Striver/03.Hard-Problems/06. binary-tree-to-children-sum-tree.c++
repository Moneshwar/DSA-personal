// https://www.youtube.com/watch?v=fnmisPM6cVo&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=30
// Can't find problem with this better watch this video feels like a good practice question

    void changeTree(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        int child = 0;
        if (root->left) {
            child += root->left->val;
        }
        if (root->right) {
            child += root->right->val;
        }
        if (child >= root->val) {
            root->val = child;
        } else {
            if (root->left) {
                root->left->val = root->val;
            } else if (root->right) {
                root->right->val = root->val;
            }
        }
        changeTree(root->left);
        changeTree(root->right);
        int tot = 0;
        if (root->left) {
            tot += root->left->val;
        }
        if (root->right) {
            tot += root->right->val;
        }
        if (root->left or root->right) {
            root->val = tot;
        }
    }