// https://leetcode.com/problems/binary-search-tree-iterator

class BSTIterator {
private:
    stack<TreeNode*> myStack;
    void pushAll(TreeNode* root) {
        while(root != NULL){
            myStack.push(root);
            root = root->left;
        }
    }
public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode* nextNode = myStack.top();
        myStack.pop();
        pushAll(nextNode->right);
        return nextNode->val;
    }
    
    bool hasNext() {
        return !myStack.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */


//  Logic:
// If we do inorderder traversal and store it in an array then we can easily do it
// Here we do the same instead of storing in an array we use stack and update it
// as we proceed to reduce space complexsity to height from N



// Its easy to get before also (in reverse order)
// go left first and then insert right nodes
// reverse inorder => right root left (This will get decending order sorted array)