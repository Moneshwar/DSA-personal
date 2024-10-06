// https://www.geeksforgeeks.org/problems/children-sum-parent/1
// To check whether the given tree is a vaild childSumTree or not
// Not a part of striver's sheet but still feels important

class Solution{
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    bool isChildSum(Node* root) {
        if(root == NULL || (root->left == NULL && root->right == NULL))
            return true;
        int expectedSum = root->data;
        int currentSum = 0;
        if(root->left)
            currentSum += root->left->data;
        if(root->right)
            currentSum += root->right->data;
        return (
            expectedSum == currentSum &&
            isChildSum(root->left) &&
            isChildSum(root->right)
            );
    }
    int isSumProperty(Node *root)
    {
        return isChildSum(root);
    }
};