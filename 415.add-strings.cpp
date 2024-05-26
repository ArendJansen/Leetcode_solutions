/*
 * @lc app=leetcode id=415 lang=cpp
 *
 * [415] Add Strings
 */

// @lc code=start
class Solution {
public:
    string addStrings(string num1, string num2) {
        std::string res;
        int num1l = num1.length(), num2l = num2.length();
        int len = std::max(num1l, num2l);
        int trail = 0, b;
        for (int i = 0; i < len; ++i){
            b = trail;
            trail = 0;
            if (i < num1l){
                b += num1[num1l - i -1] - '0';
            }
            if (i < num2l){
                b += num2[num2l - i - 1] - '0';
            }
            if (b > 9){
                b = b % 10;
                trail = 1;
            }
            res = std::to_string(b) + res;

        }

        if (trail == 1){
            res = '1' + res;
        }
        return res;
    }
};
// @lc code=end

