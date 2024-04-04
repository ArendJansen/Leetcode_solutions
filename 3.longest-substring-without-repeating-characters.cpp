/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
# include <unordered_set>
#include <unordered_map>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_count = 0;
        int curr_count = 0;
        int j = 0;
        std::unordered_map<char,int> v;

        for (int i = 0; i < s.size(); ++i){
            if (v.count(s[i]) > 0 && v[s[i]] >= j){
                j = v[s[i]];
                curr_count = i - v[s[i]];
                v[s[i]] = i;
            }
            else {
                v[s[i]] = i;
                ++curr_count;
                if (curr_count > max_count){
                    max_count = curr_count;
                }
            }
        }

        return max_count;

    
    }
};
// @lc code=end

