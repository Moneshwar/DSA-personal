// https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
public:
    bool isLeaf(Node* root){
        return root->left == NULL && root->right == NULL;
    }
    void addLeft(Node* root,vector<int>& res) {
         while(root != NULL) {
            if(!isLeaf(root))
                res.push_back(root->data);
            if(root->left != NULL)
                root = root->left;
            else
                root = root->right;
        }
    }
    void addLeaves(Node* root , vector<int>& res) {
        if(isLeaf(root)){
            res.push_back(root->data);
            return;
        }
        if(root->left != NULL)
            addLeaves(root->left,res);
        if(root->right != NULL)
            addLeaves(root->right,res);
    }
    void addRight(Node* root , vector<int>& res) {
        vector<int> temp;
         while(root != NULL) {
            if(!isLeaf(root))
                temp.push_back(root->data);
            if(root->right != NULL)
                root = root->right;
            else
                root = root->left;
        }
        reverse(temp.begin(),temp.end());
        for(int i:temp)
            res.push_back(i);
    }
    vector <int> boundary(Node *root)
    {
        vector<int> res;
        if(root == NULL)
            return res;
        // Having this to prevent duplicate which can we added by addLeaves
        if(!isLeaf(root)){
            res.push_back(root->data);
        }
        addLeft(root->left,res);
        addLeaves(root,res);
        addRight(root->right,res);
        return res;
    }
};