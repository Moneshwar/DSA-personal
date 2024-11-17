// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

//  Note: Inorder traversal will give us sorted array

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int res = -1;
        int count = 0;
        TreeNode* node = root;
        stack<TreeNode*> st;
        while(true){
            if(node == NULL){
                if(st.empty())
                    break;
                node = st.top();
                st.pop();
                count++;
                if(count == k){
                    res = node->val;
                    break;
                }
                node = node->right;
            }
            else{
                st.push(node);
                node = node->left;
            }
        }
        return res;
    }
};

// If we want to find the kth largest element
// then we need to find the (n-k)th smallest element