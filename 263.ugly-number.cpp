/*
 * @lc app=leetcode id=263 lang=cpp
 *
 * [263] Ugly Number
 */

// @lc code=start
class Solution {
public:
    bool isUgly(int n) {

        if (n == 0){
            return false;
        }
        if (n == 1){
            return true;
        }
        if (n == -2147483648) {
            return false;
        }

        for (int i = 2; i <= 5 ; ++i){
            while (n % i == 0){
                n /= i;
            }
        }
        return n == 1;
        
    }
};
// @lc code=end

