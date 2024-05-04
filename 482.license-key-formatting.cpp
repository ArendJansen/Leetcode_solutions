/*
 * @lc app=leetcode id=482 lang=cpp
 *
 * [482] License Key Formatting
 */

// @lc code=start
#include <string> 
class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        std::string res;
        int curr = 0;
        for (int i = s.length() - 1; i >= 0; --i){
            if (s[i] != '-'){
                if (std::islower(s[i])){
                    s[i] = std::toupper(s[i]);
                }

                if (curr < k){
                    res += s[i];
                    ++curr;    
                }
                else if (curr == k){
                    res += '-';
                    res += s[i];
                    curr = 1;
                }

            }
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

