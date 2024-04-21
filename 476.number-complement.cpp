/*
 * @lc app=leetcode id=476 lang=cpp
 *
 * [476] Number Complement
 */

// @lc code=start
class Solution {
public:
    int findComplement(int num) {
        long long x = 1;
        while (x <= num){
            x <<= 1;
        }
        --x;
        return (x^num);
    }
};
// @lc code=end

