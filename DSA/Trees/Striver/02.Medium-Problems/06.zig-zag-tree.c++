// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        bool isReverse = false;
        while(!q.empty()){
            vector<int> level;
            int size = q.size();
            for(int i = 0;i<size;i++){
                TreeNode* temp = q.front();
                q.pop();
                level.push_back(temp->val);
                if(temp->left != NULL)
                    q.push(temp->left);
                if(temp->right != NULL)
                    q.push(temp->right);
            }
            if(isReverse){
                reverse(level.begin(),level.end());
            }
            isReverse = !isReverse;
            res.push_back(level);
        }
        return res;
    }
};
// ----

// Here we can prevent the reverse operation in the above code
// by using an extra variable to track the direction of traversal


        while(!nodesQueue.empty()){
            int size = nodesQueue.size();
            vector<int> row(size);
            for(int i = 0; i < size; i++){
                Node* node = nodesQueue.front();
                nodesQueue.pop();
                int index = leftToRight ? i : (size - 1 - i);
                row[index] = node->data;
                if(node->left){
                    nodesQueue.push(node->left);
                }
                if(node->right){
                    nodesQueue.push(node->right);
                }
            }
            leftToRight = !leftToRight;
            result.push_back(row);
        }
