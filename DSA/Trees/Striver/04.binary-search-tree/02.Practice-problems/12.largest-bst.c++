// https://www.geeksforgeeks.org/problems/largest-bst/1

class CustomNode {
    public:
    int maxValue , minValue , size;
    CustomNode(int minV , int maxV , int s){
        maxValue = maxV;
        minValue = minV;
        size = s;
    }
};

class Solution{
    public:
    CustomNode largestBstHelper(Node* root) {
        if(root == NULL)
            return CustomNode(INT_MAX , INT_MIN , 0);
        CustomNode left = largestBstHelper(root->left);
        CustomNode right = largestBstHelper(root->right);
        if(left.maxValue < root->data and root->data < right.minValue) {
            // Valid bst
            return CustomNode(
                min(left.minValue , root->data) ,
                max(root->data , right.maxValue) ,
                1+ left.size + right.size);
        }
        return CustomNode(INT_MIN , INT_MAX , max(left.size , right.size));
    }
    int largestBst(Node *root)
    {
    	return largestBstHelper(root).size;
    }
};
// Easy one only but difficult to comeup with solution