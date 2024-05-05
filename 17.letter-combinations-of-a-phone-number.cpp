/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
#include <vector>
#include <string>

std::vector<std::string> makeCombs(
    std::vector<std::string> & original,
    std::string new_combs){
        
        std::vector<std::string> res;
        
        for (int i = 0; i < original.size(); ++i){
            for (int j = 0; j < new_combs.length(); ++j){
                res.push_back(original[i] + new_combs[j]);
            }
        }

        return res;

    }

class Solution {
public:
    vector<string> letterCombinations(string digits) {

        if (digits == ""){
            return std::vector<std::string>{};
        }

        std::string phone_map[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        std::vector<std::string> res(1,"");
        std::string curr;

        for (int i = 0 ; i < digits.length(); ++i){
            if (digits[i] != '1'){
                curr = phone_map[digits[i] - '2'];
                res = makeCombs(res,curr);
            }
        }
        return res;
        
    }
};
// @lc code=end

