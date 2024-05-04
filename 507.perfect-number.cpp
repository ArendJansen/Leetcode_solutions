/*
 * @lc app=leetcode id=507 lang=cpp
 *
 * [507] Perfect Number
 */

// @lc code=start
class Solution {
public:
    bool checkPerfectNumber(int num) {
        int total = 0;

        for (int i = 1; i <= num / 2; ++i){
            if (num % i == 0){
                total += i;
            }
        }
        return total == num;
        
    }
};
// @lc code=end

