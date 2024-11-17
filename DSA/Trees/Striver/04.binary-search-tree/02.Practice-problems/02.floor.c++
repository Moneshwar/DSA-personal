// https://www.geeksforgeeks.org/problems/floor-in-bst/1

class Solution{
public:
    int floor(Node* root, int input) {
        if (root == NULL) return -1;
        int floor = -1;
        while(root != NULL) {
            if(root->data == input){
                return input;
            }
            if(root->data > input) {
                root = root->left;
            }
            else{
                floor = root->data;
                root = root->right;
            }
        }
        return floor;
    }
};