// https://www.geeksforgeeks.org/problems/minimum-element-in-bst/1

// Minimum:
class Solution {
  public:
    int minValue(Node* root) {
        while(root->left != NULL)
            root = root->left;
        return root->data;
    }
};

// Maximum:
class Solution {
  public:
    int maxValue(Node* root) {
        while(root->right != NULL)
            root = root->right;
        return root->data;
    }
};