// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/

class BSTIterator{
    stack<TreeNode*> st;
    bool right;
    void push(TreeNode* root){
        while(root){
            st.push(root);
            if(!right){
                root=root->left;
            }
            else{
                root=root->right;
            }
        }
    }
    public:
    BSTIterator(TreeNode* root,bool right=false){
        this->right=right;
        push(root);
    }
    int next(){
        int ans=st.top()->val;
        TreeNode* root=st.top();
        st.pop();
        if(!right){
            push(root->right);
        }
        else{
            push(root->left);
        }
        return ans;
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator l(root,false);
        BSTIterator r(root,true);
        int nodel=l.next();
        int noder=r.next();
        while(nodel<noder){
            int sum=nodel+noder;
            if(sum==k)
                return true;
            if(sum>k){
                noder=r.next();
            }
            else{
                nodel=l.next();
            }
        }
        return false;
    }
};


//  Most code is copy pasted from previous question 09.bst-treaversal
// If we generate a inorder it becomes a normal 2-sum in a sorted array
// But it will take space O(N)
// To optimise it we are using the stack approach