/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 */

// @lc code=start
#include <unordered_map>
class Solution {
public:
    int firstUniqChar(string s) {
        std::unordered_map<char,int> lmap;

        for (int i = 0; i < s.size(); ++i){
           lmap[s[i]]++;
        }
        for (int i = 0; i < s.size(); ++i){
            if (lmap[s[i]] == 1){
                return i;
            }
        }

        return -1;


    }
};
// @lc code=end

