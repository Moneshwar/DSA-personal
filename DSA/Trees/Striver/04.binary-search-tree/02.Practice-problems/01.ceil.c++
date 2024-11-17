// https://www.geeksforgeeks.org/problems/implementing-ceil-in-bst/1

// Function to return the ceil of given number in BST.
int findCeil(Node* root, int input) {
    if (root == NULL) return -1;
    int ceil = -1;
    while(root != NULL) {
        if(root->data == input){
            return input;
        }
        if(root->data < input) {
            root = root->right;
        }
        else{
            ceil = root->data;
            root = root->left;
        }
    }
    return ceil;
}