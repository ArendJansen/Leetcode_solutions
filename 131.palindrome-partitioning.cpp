/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 */

// @lc code=start

#include <string>
#include <vector>
using namespace std;

bool isPalindrome(const string & s){
    int l = 0, r = s.length() -1;

    while (r > l){
        if (s[r] != s[l]){
            return false;
        }
        --r;
        ++l;
    }
    return true;
}

bool isValidPartition(const vector<string> & s){
    for (int i = 0;  i < s.size(); ++i){
        if (!isPalindrome(s[i])){
            return false;
        }
    }
    return true;
}

void Solve(
    vector<vector<string>> & sols, 
    vector<string> & state,
     const string & s, 
     int curr){
    if (curr == s.length()){
        if (isValidPartition(state)){
            sols.push_back(state);
        }
        return;
    }

    string tmp(1, s[curr]);

    state.push_back(tmp);
    Solve(sols,state,s,curr+1);
    state.pop_back();
    state.back().push_back(s[curr]);
    Solve(sols,state,s,curr+1);
    state.back().pop_back();
 
}

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> sols;
        int curr;
        vector<string> state;
        state.push_back(std::string(1,s[0]));
        Solve(sols,state,s,1);
        return sols;



        
    }
};
// @lc code=end

