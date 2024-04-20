/*
 * @lc app=leetcode id=392 lang=cpp
 *
 * [392] Is Subsequence
 */

// @lc code=start
#include <queue>
#include <string>
class Solution {
public:
    bool isSubsequence(string s, string t) {
        std::queue<char> lq;

        if (t.length() == 0 & s.length() != 0){
            return false;
        }
        if (s.length() == 0){
            return true;
        }

        for (int i = 0; i < t.length(); ++i){
            if (t[i] == s[0]){
                s.erase(s.begin());
                if (s.length() == 0){
                    return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end

