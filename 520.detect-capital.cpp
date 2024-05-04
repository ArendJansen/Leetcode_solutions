/*
 * @lc app=leetcode id=520 lang=cpp
 *
 * [520] Detect Capital
 */

// @lc code=start
class Solution {
public:
    bool detectCapitalUse(string word) {
        bool set = false;

        for (int i = 0; i < word.size(); ++i){

            if (i > 1 && set && std::isupper(word[i])){
                return false;
            } 
            else if (i > 1 && !set && std::islower(word[i])){
                return false;
            }        
            else if (i <= 1 && std::islower(word[i])){
                set = true;
            } 
            else if (i == 1 && set && std::isupper(word[i]) ){
                return false; 
            }
            
        }
        return true;
        
    }
};
// @lc code=end

