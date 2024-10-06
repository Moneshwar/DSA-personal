// Code only big but easy question only.
// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

class Solution {
public:
    void assignParentNodes(TreeNode* root , unordered_map<TreeNode* , TreeNode*>& parentMap){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* currentHead = q.front();
            q.pop();
            if(currentHead->left) {
                q.push(currentHead->left);
                parentMap[currentHead->left] = currentHead;
            }
            if(currentHead->right) {
                q.push(currentHead->right);
                parentMap[currentHead->right] = currentHead;
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
         unordered_map<TreeNode* , TreeNode*> parentMap;
         assignParentNodes(root , parentMap);
         unordered_set<TreeNode*> visited;
         queue<TreeNode*> q;
         visited.insert(target);
         q.push(target);
         for(int i = 0; i<k ;i++) {
            int size = q.size();
            for(int j = 0 ; j < size ; j++) {
                TreeNode* currentHead = q.front();
                q.pop();
                if(currentHead->left && 
                    visited.find(currentHead->left) == visited.end()) {
                    q.push(currentHead->left);
                    visited.insert(currentHead->left);
                }
                if(currentHead->right && 
                    visited.find(currentHead->right) == visited.end()){
                    q.push(currentHead->right);
                    visited.insert(currentHead->right);
                }
                if(parentMap.find(currentHead)!=parentMap.end() 
                    && visited.find(parentMap[currentHead]) == visited.end()) {
                    q.push(parentMap[currentHead]);
                    visited.insert(parentMap[currentHead]);
                }
            }
        }
        vector<int> ans;
        while(!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};