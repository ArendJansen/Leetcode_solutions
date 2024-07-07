/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start

#include <string>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    bool helper(string s, vector<string>& wordDict, int r, map<int,bool> & cache){
        string tmp;
        bool ltrue = false;
        if (r == s.length()){
            return cache[r] = true;
        }
        if (cache.count(r) > 0){
            return cache[r];
        }


        while (r < s.length()){
            tmp += s[r];
            for (int i = 0;  i < wordDict.size(); ++i){
                if (tmp == wordDict[i]){
                    cache[r+1] = helper(s,wordDict,r+1, cache);
                    if (cache[r+1] == true){return true;}
                }
            }
        ++r;
        }

        return cache[r] = false;


        // curr += s[r];
        // for (int i = 0;  i < wordDict.size(); ++i){
        //     if (curr == wordDict[i]){
        //         bool ltrue = 
        //     }
        // }
    }
    bool wordBreak(string s, vector<string>& wordDict){
        std::map<int,bool> cache;
        return helper(s,wordDict,0,cache);


    }
};
// @lc code=end

