/*
 * @lc app=leetcode id=504 lang=cpp
 *
 * [504] Base 7
 */

// @lc code=start
class Solution {
public:
    string convertToBase7(int num) {
    
        if (num == 0){
            return "0";
        }
        bool neg = num < 0 ? true : false;

        std::string res;

        while (abs(num) > 0){

            res += std::to_string((abs(num) % 7));
            num = num/7;
        }
        std::reverse(res.begin(), res.end());

        if (neg){
            res.insert(0,1,'-');
        }
        return res;
        
    }
};
// @lc code=end

