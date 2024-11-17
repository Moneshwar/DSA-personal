// https://leetcode.com/problems/insert-into-a-binary-search-tree/

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* nodeToInsert = new TreeNode(val);
        if(root == NULL)
            return nodeToInsert;
        TreeNode* temp = root;
        while(true) {
            if(temp->val < val) {
                if(temp->right != NULL)
                    temp = temp->right;
                else
                    break;
            }
            else {
                 if(temp->left != NULL)
                    temp = temp->left;
                else
                    break;
            }
        }
        if(temp->val < val)
            temp->right = nodeToInsert;
        else
            temp->left = nodeToInsert;
        return root;
    }
};