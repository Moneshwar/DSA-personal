// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
// Need lot and lots of practice
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> inOrderIndexedMap;
        int k = 0;
        for(int i : inorder){
            inOrderIndexedMap[i] = k++;
        }
        int n1 = preorder.size()-1;
        int n2 = inorder.size()-1;
        TreeNode* root = generateTree(preorder,0,n1,inorder,0,n2,inOrderIndexedMap);
        return root;
    }
    TreeNode* generateTree(vector<int>& preorder , int preStart , int preEnd , 
                            vector<int>& inorder , int inStart , int inEnd , 
                            unordered_map<int,int>& inOrderIndexedMap){
        if(preStart>preEnd || inStart > inEnd)
            return NULL;
        TreeNode* root = new TreeNode(preorder[preStart]);
        int inRoot = inOrderIndexedMap[root->val];
        int numLeft = inRoot - inStart;
        root->left = generateTree(preorder,preStart+1 , preStart + numLeft , inorder , inStart , inRoot - 1 , inOrderIndexedMap);
        root->right = generateTree(preorder,preStart+numLeft + 1 , preEnd , inorder , inRoot+1 , inEnd , inOrderIndexedMap);
        return root;
    }
};