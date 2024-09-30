// Brutto Force solution
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

    int maxDepth(TreeNode* root) {
        //FROM: https://leetcode.com/problems/maximum-depth-of-binary-tree/
        if(!root)
            return 0;
        int left=maxDepth(root->left);
        int right=maxDepth(root->right);
        return 1+max(left,right); 
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
            return true;
        int lHeight = maxDepth(root->left);
        int rHeight = maxDepth(root->right);
        if(abs(lHeight-rHeight) <= 1){
            if(isBalanced(root->left) && isBalanced(root->right)) {
                    return true;
                }
            return false;
        }
        return false;
    }
};

//  TC - O(N^2)
//  SC - O(N)

// ---------------------------------------------------------------------
//  Optimized solution

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

    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        int left=maxDepth(root->left);
        if(left == -1)
            return -1;
        int right=maxDepth(root->right);
        if(right == -1)
            return -1;
        if(abs(left-right) > 1)
            return -1;
        return 1+max(left,right); 
    }
    bool isBalanced(TreeNode* root) {
       return maxDepth(root)!=-1;
    }
};