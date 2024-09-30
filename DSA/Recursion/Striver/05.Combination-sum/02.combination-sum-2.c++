// Leetcode: https://leetcode.com/problems/combination-sum-ii/
class Solution {
public:
    void helper(int index , int target , vector<int> candidates ,vector<vector<int>> &ans , vector<int> data) {
        if(target == 0){
            ans.push_back(data);
            return;
        }

        for(int i=index ; i<candidates.size();i++){
            // To prevent duplicates;
            if(i > index && candidates[i]==candidates[i-1])
                continue;
            // Since sorted adding more numbers will not provide the required sum
            if(candidates[i] > target)
                break;
            data.push_back(candidates[i]);
            helper(i+1,target-candidates[i],candidates,ans,data);
            data.pop_back();
        }

    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> data;
        helper(0,target,candidates,ans,data);
        return ans;
    }
};