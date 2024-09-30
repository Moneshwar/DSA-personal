// Leetcode: https://leetcode.com/problems/combination-sum/
class Solution {
public:
        
    void fun(int i , int target ,
            vector<int>& arr, vector<vector<int>>& ans ,vector<int>& ds) {
        if(i==arr.size())
        {
            if(target==0)
                ans.push_back(ds);
            return;
        }
        if(arr[i]<=target)
        {
            // Same index we can add many times so we don't increment index
            ds.push_back(arr[i]);
            fun(i,target-arr[i],arr,ans,ds);
            ds.pop_back();
        }
        fun(i+1,target,arr,ans,ds);
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        fun(0,target,candidates,ans,ds);
        return ans;
        
    }
};


// TC- O(2^t) ==> where t can be any t >= n 