/*
 * @lc app=leetcode id=509 lang=cpp
 *
 * [509] Fibonacci Number
 */

// @lc code=start
class Solution {
public:
    int fib(int n) {
        if (n < 2){
            return n;
        }

        int i, res = 0;
        int j = 1;

        while (n > 1){
            res = i + j;
            i = j;
            j = res;
            --n;
        }

        return res;
    
    }
};
// @lc code=end

