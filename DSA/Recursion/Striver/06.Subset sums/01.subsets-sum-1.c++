// GFG Link: https://www.geeksforgeeks.org/problems/subset-sums2234/1

class Solution {
  public:
    void helper(vector<int> arr , vector<int> &res , int index,int sum){
        if(index == arr.size()){
             res.push_back(sum);
            return;
        }
        helper(arr,res,index+1 , sum+arr[index]);
        helper(arr,res,index+1 , sum);
    }
    vector<int> subsetSums(vector<int> arr, int n) {
       vector<int> res;
       helper(arr,res,0,0);
       return res;
    }
};