/*
 * @lc app=leetcode id=290 lang=cpp
 *
 * [290] Word Pattern
 */

// @lc code=start
#include <unordered_map>
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        std::unordered_map<char, std::string> rmap;
        std::unordered_map<std::string, char> lmap;
        std::string wordque;
        int n = 0;
        int b = s.length();

        for (int i = 0; i < pattern.length(); ++i){
            if (n == b){
                return false;
            }
            while (s[n] != ' ' && n != s.length()){
                wordque += s[n];
                ++n;
            }
            if (n < b){
                ++n;
            }
            if (rmap.find(pattern[i]) == rmap.end() && lmap.find(wordque) == lmap.end()){
                rmap[pattern[i]] = wordque;
                lmap[wordque] = pattern[i];
            }
            else if (rmap[pattern[i]] != wordque || lmap[wordque] != pattern[i]) {
                return false;
            }
            
            wordque.clear();

        }

        if (n < b){
            return false;
        }


        return true;
        
    }
};
// @lc code=end

