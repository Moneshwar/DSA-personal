// https://leetcode.com/problems/count-complete-tree-nodes/solutions/
//  Optimal Way
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == NULL)
            return 0;
        int left = leftHeight(root);
        int right = rightHeight(root);
        if(left == right)
            return pow(2,left) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    int leftHeight(TreeNode* root) {
        int count = 0;
        while(root){
            count++;
            root = root->left;
        }
        return count;
    }
    int rightHeight(TreeNode* root) {
        int count = 0;
        while(root){
            count++;
            root = root->right;
        }
        return count;
    }
};


// Tc - O(Log(N)^2)
// Sc - O(Log(N))  -> Height of Tree here its Log(N) because its a complete tree