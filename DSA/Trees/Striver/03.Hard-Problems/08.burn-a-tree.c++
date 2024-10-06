//https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/description/

// Solution only big...
// But good to understand

class Solution {
public:
    TreeNode* assignParentNodes(TreeNode* root , unordered_map<TreeNode* , TreeNode*>& parentMap,int target){
        queue<TreeNode*> q;
        TreeNode* targetNode;
        q.push(root);
        while(!q.empty()) {
            TreeNode* currentHead = q.front();
            q.pop();
            if(currentHead->val == target)
                targetNode = currentHead;
            if(currentHead->left) {
                q.push(currentHead->left);
                parentMap[currentHead->left] = currentHead;
            }
            if(currentHead->right) {
                q.push(currentHead->right);
                parentMap[currentHead->right] = currentHead;
            }
        }
        return targetNode;
    }
    int calculateMinimumTime(TreeNode* target , unordered_map<TreeNode* , 
                            TreeNode*>& parentMap) {
        int ans = 0;
        unordered_map<TreeNode*,bool> visited;
        visited[target] = true;
        queue<TreeNode*> q;
        q.push(target);
        while(!q.empty()){
            bool flag = false;
            int size = q.size();
            for(int i = 0 ; i < size ; i++) {
                TreeNode* currentNode = q.front();
                q.pop();
                if(currentNode->left && !visited[currentNode->left]) {
                    visited[currentNode->left] = true;
                    flag = true;
                    q.push(currentNode->left);
                }
                if(currentNode->right && !visited[currentNode->right]) {
                    visited[currentNode->right] = true;
                    flag = true;
                    q.push(currentNode->right);
                }
                if(parentMap.find(currentNode) != parentMap.end() &&
                    !visited[parentMap[currentNode]]) {
                    visited[parentMap[currentNode]] = true;
                    flag = true;
                    q.push(parentMap[currentNode]);
                }
            }
            if(flag)
                ans++;
        }
        return ans;
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode* , TreeNode*> parentMap;
        TreeNode* targetNode = assignParentNodes(root,parentMap,start);
        int res = calculateMinimumTime(targetNode,parentMap);
        return res;
    }
};