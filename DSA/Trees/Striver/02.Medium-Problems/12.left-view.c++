// https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1
// Only small difference between left and right view
void dfs(Node* root , vector<int>& ans , int level) {
        if(root == NULL)
            return;
        if(level == ans.size())
            ans.push_back(root->data);
        // To get left view
        dfs(root->left , ans , level+1);
        dfs(root->right , ans , level+1);

    }
vector<int> leftView(Node *root)
{
    vector<int> ans;
    dfs(root,ans,0);
    return ans;
}


// Note: 
// We can also solve this with level order but code will be big

