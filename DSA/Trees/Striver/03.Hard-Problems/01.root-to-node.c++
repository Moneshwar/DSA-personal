// Important Question but no practice site available

bool hasPath(Node *root, vector<int>& arr, int x)
{
    if (!root)
        return false;
    arr.push_back(root->data);    
    if (root->data == x)    
        return true;

    if (hasPath(root->left, arr, x) ||
        hasPath(root->right, arr, x))
        return true;
    arr.pop_back();
    return false;            
}