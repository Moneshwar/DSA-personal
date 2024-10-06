// https://leetcode.com/problems/maximum-width-of-binary-tree/
// https://takeuforward.org/data-structure/maximum-width-of-a-binary-tree/

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        int ans = 0;
        queue<pair<TreeNode* , int>> q;
        q.push({root,0});
        while(!q.empty()){
            int to_subract_id = q.front().second;
            int left , right;
            int size = q.size();
            for(int i = 0 ; i < size ; i++) {
                TreeNode* top = q.front().first;
                int current_id =  q.front().second - to_subract_id;
                q.pop();
                if(i == 0)
                    left = current_id;
                if(i == size - 1)
                    right = current_id;
                if(top->left)
                    q.push({top->left,((long long)2*current_id)+1});
                if(top->right)
                    q.push({top->right,((long long)2*current_id)+2});
            }
            ans = max(ans,right - left + 1);
        }
        return ans;
    }
};

// This is a easy question ---> But overflow only makes it difficult
// In strivers solution type casting to long long is missing

// Reason:
// If you are getting runtime error while submiting the same code on leetcode,no need to worry,just do a minute change in the code,
// just typecast the value of index while pushing in the queue.You may ask since we applied a trick to tackle the integer overflow here,
// yes we did,but through this method we just ensure that the index we push everytime just comes under INT_MAX,and index difference is always under singed 32 bit ,
// i.e at max below 2^32 as stated in question itself. At everytime we are pushing (2*index+1) or (2*index+2),so its not exactly twice,its getting more than that ,
// thats why we need to typecast with long long.Hope its clear now.
