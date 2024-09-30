// Leetcode: https://leetcode.com/problems/permutations/description/


// NOTE: There will be N! permutations 
class Solution {
public:
    void helper(vector<int> nums , 
                vector<vector<int>> &ans , int freq[] ,vector<int> ds) {
        if(ds.size() == nums.size()) {
            ans.push_back(ds);
            return;
        }
        for(int i = 0 ; i < nums.size() ; i++) {
            if(freq[i] == 0){
                freq[i] = 1;
                ds.push_back(nums[i]);
                helper(nums , ans ,freq , ds);
                ds.pop_back();
                freq[i] = 0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        int freq[nums.size()];
        for(int i = 0;i < nums.size() ; i++) {
            freq[i] = 0;
        }
        helper(nums , ans , freq , ds);
        return ans;
    }
};

// TC - O(n!* n)
// SC - O(n)