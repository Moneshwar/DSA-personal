// https://leetcode.com/problems/palindrome-partitioning
class Solution {
public:
    bool isPalindrome(string s,int start,int end) {
        while(start<=end) {
            if(s[start]!=s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
    void fun(int index,string s,vector<vector<string>>& result,
            vector<string>& ds) {
        if(index==s.length()) {
            result.push_back(ds);
            return;
        }
        for(int i=index ; i<s.length() ; i++) {
            if(isPalindrome(s,index,i)) {
                ds.push_back(s.substr(index,i-index+1));
                fun(i+1,s,result,ds);
                ds.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> ds;
        fun(0,s,result,ds);
        return result;
    }
};


// -------------------------------- 

// Explanation:
// when a substring is a palindrome we push it in the DS 
// and call the recursion for other part of the string