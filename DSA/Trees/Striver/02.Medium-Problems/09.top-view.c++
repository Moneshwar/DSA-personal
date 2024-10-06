// https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1
//  Prereqquisite Vertical order traversal 

class Solution
{
    public:
    vector<int> topView(Node *root)
    {
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
            if(mp.find(currentLevel) == mp.end())
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