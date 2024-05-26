/*
 * @lc app=leetcode id=459 lang=cpp
 *
 * [459] Repeated Substring Pattern
 */

// @lc code=start
#include <string>
class Solution {
public:
    bool repeatedSubstringPattern(string s) {

        int len = s.length();

        if (len == 1){
            return false;
        }

        for (int i = 1; i <= len / 2; ++i){
            if (len % i == 0){
                std::string test = s.substr(0,i);
                std::string test2;
                for (int j = 1; j <= len / i; ++j ){
                    test2 += test;
                }
                if (test2 == s){
                    return true;
                }
            }
        }
        return false;
        
    }
};
// @lc code=end

