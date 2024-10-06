// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal
// Very similar to previous question

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> inOrderIndexedMap;
        int k = 0;
        for(int i : inorder){
            inOrderIndexedMap[i] = k++;
        }
        int n1 = postorder.size()-1;
        int n2 = inorder.size()-1;
        TreeNode* root = generateTree(postorder,0,n1,inorder,0,n2,inOrderIndexedMap);
        return root;
    }
    TreeNode* generateTree(vector<int>& postorder , int postStart , int postEnd , 
                            vector<int>& inorder , int inStart , int inEnd , 
                            unordered_map<int,int>& inOrderIndexedMap){
        if(postStart>postEnd || inStart > inEnd)
            return NULL;
        TreeNode* root = new TreeNode(postorder[postEnd]);
        int inRoot = inOrderIndexedMap[root->val];
        int numLeft = inRoot - inStart;
        root->left = generateTree(postorder,postStart , postStart + numLeft-1 , inorder , inStart , inRoot - 1 , inOrderIndexedMap);
        root->right = generateTree(postorder,postStart+numLeft , postEnd-1 , inorder , inRoot+1 , inEnd , inOrderIndexedMap);
        return root;
    }
};