/*
 * @lc app=leetcode id=389 lang=cpp
 *
 * [389] Find the Difference
 */

// @lc code=start
#include <unordered_map>
class Solution {
public:
    char findTheDifference(string s, string t) {
        std::unordered_map<char,int> lmap;
        for (auto c: t){
            ++lmap[c];
        }
        for (auto c: s){
            --lmap[c];
        }

        for (auto it = lmap.begin(); it != lmap.end(); ++ it){
            if (it -> second > 0){
                return it -> first;
            }
        }
        return 0;
    }
};
// @lc code=end

