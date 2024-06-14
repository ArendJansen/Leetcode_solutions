/*
 * @lc app=leetcode id=1768 lang=cpp
 *
 * [1768] Merge Strings Alternately
 */

// @lc code=start
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        std::string res;
        int len = std::min(word1.length(), word2.length());
        
        for (int i = 0; i < len; ++i){
            res += word1[i];
            res += word2[i];    
        }
        if (word1.length() > word2.length()){
            res += word1.substr(len);
        }
        else if (word2.length() > word1.length()){
            res += word2.substr(len);
        }
        return res;
    }
};
// @lc code=end

