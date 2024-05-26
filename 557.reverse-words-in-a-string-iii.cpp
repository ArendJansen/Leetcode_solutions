/*
 * @lc app=leetcode id=557 lang=cpp
 *
 * [557] Reverse Words in a String III
 */

// @lc code=start
#include <algorithm>
class Solution {
public:
    string reverseWords(string s) {

        int l = 0, r = 0;
        bool at_space = false;
        for (int i = 0; i < s.length(); ++i){
            if (s[i] != ' ' && !at_space){
                r = i;
            }
            else if (s[i] != ' ' && at_space){
                l = i;
                r = i;
                at_space = false;
            }
            else if (!at_space){
                while (l < r){
                    std::swap(s[l],s[r]);
                    ++l,
                    --r;
                }
                at_space = true;
            }
            else {
                continue;
            }

            if (i == s.length() - 1){
                while (l < r){
                    std::swap(s[l],s[r]);
                    ++l,
                    --r;
                }
            }
        }

        return s;
        
    }
};
// @lc code=end

