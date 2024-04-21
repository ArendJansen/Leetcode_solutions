/*
 * @lc app=leetcode id=405 lang=cpp
 *
 * [405] Convert a Number to Hexadecimal
 */

// @lc code=start

#include <string> 
#include <algorithm>

char numberToChar(int n){
    if (n >= 0 && n <= 9){
        return '0' + n;
    }
    else if (n > 9){
        return 'a' + n - 10;
    }
    return '0';
}
class Solution {
public:
    string toHex(int num) {

        std::string res;

        if (num >= 0){
            while (num >0){
                res += numberToChar(num % 16);
                num = num / 16;
            }
        }
        if (num < 0){
            // int two_comp_num = ~num + 1;
            unsigned int two_comp_num = static_cast<unsigned int>(num);
            while (two_comp_num >0){
                res += numberToChar(two_comp_num % 16);
                two_comp_num = two_comp_num / 16;
            }
        }
        if (res.empty()){
            return "0";
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

