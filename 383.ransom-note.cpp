/*
 * @lc app=leetcode id=383 lang=cpp
 *
 * [383] Ransom Note
 */

// @lc code=start
#include <unordered_map>
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        std::unordered_map<char,int> lmap;

        for (int i = 0; i < magazine.length(); ++i){
            ++lmap[magazine[i]];
        }
        for (int i = 0; i < ransomNote.size(); ++i){
            if (lmap.find(ransomNote[i]) != lmap.end() &&
            lmap[ransomNote[i]] > 0){
                --lmap[ransomNote[i]];
            }
            else{
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

