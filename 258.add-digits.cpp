/*
 * @lc app=leetcode id=258 lang=cpp
 *
 * [258] Add Digits
 */

// @lc code=start
class Solution {
public:
    int addDigits(int num) {

        if (num < 10){
            return num;
        }
        int result;
        std::string str_num = std::to_string(num);
        
        while (str_num.length() > 1){
            result = 0;
            for (char s : str_num){
                result +=  (s - '0');
            }
            str_num = std::to_string(result);  
        }
        return result;
        
    }
};
// @lc code=end

