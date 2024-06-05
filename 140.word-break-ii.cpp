/*
 * @lc app=leetcode id=140 lang=cpp
 *
 * [140] Word Break II
 */

// @lc code=start

#include <vector>
#include <string>

using namespace std;

bool inWordDict(
    const vector<string> & dict,
    const string & word){
        for (string w : dict){
            if (w == word) {return true;}
        }
        return false;   
}

void Solve(
    vector<string> & sols,
    string & state,
    string & state2,
    int curr,
    const string & s,
    const vector<string>& wordDict){
        
        if (curr == s.length()){
            
            if(state2.length() == 0){
                sols.push_back(state);
            }
            return;
        }

        state2 += s[curr];
        string tmp = state2;
        if (inWordDict(wordDict, state2)){
            int len = state2.length();
            if (state.length() == 0){
                state += state2;
                state2.clear();
                Solve(sols,state,state2,curr+1,s, wordDict);
                state.erase(state.length() - len);
                state2 = tmp;
            }
            else {
                ++len;
                state.push_back(' ');
                state += state2;
                state2.clear();
                Solve(sols,state,state2,curr+1,s, wordDict);
                state.erase(state.length() - len);
                state2 = tmp;
            }
        }
        Solve(sols,state,state2, curr + 1,s, wordDict);
        state2.pop_back();
}

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> sols;
        string state;
        string state2;
        Solve(sols,state,state2,0,s, wordDict);

        return sols;
    }
};
// @lc code=end

