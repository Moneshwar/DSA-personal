// https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1
//  This this is very easy if we know top-view

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector<int> ans;
        if(root == NULL)
            return ans;
        // Using map so we the keys are stored in order.
        map<int,int> mp;
        queue<pair<Node*,int>> q;
        q.push({root , 0});
        while(!q.empty()){
            pair<Node* , int> current = q.front();
            Node* currentNode = current.first;
            int currentLevel = current.second;
            q.pop();
            // The only change is we store the last seen 
            // in top view we store the first viewen
            mp[currentLevel] = currentNode->data;
            if(currentNode->left != NULL)
                q.push({currentNode->left ,currentLevel - 1});
                
            if(currentNode->right != NULL)
                q.push({currentNode->right , currentLevel + 1});
        }
        for(auto it : mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};