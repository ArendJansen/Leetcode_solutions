/*
 * @lc app=leetcode id=409 lang=cpp
 *
 * [409] Longest Palindrome
 */

// @lc code=start
#include <unordered_map>
class Solution {
public:
    int longestPalindrome(string s) {

        int res = 0;
        bool odd = false;
        std::unordered_map<char,int> lmap;

        for (auto c : s){
            ++lmap[c];
        }

        for (auto it = lmap.begin(); it != lmap.end(); ++it){
            if (it -> second % 2 == 0){
                res += it -> second;
            } else {
                res += it -> second - 1;
                odd = true;
            }
        }

        if (odd){
            return res + 1;
        }
        return res;

    }
};
// @lc code=end

