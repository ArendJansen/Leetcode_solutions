/*
 * @lc app=leetcode id=231 lang=cpp
 *
 * [231] Power of Two
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfTwo(int n) {

        if (n  <= 0){
            return false;
        }

        while (n / 2 > 0){
            if (n % 2 != 0){
                return false;
            }
            n = n /2;
        }
        return true;
    }
};
// @lc code=end

