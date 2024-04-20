/*
 * @lc app=leetcode id=191 lang=cpp
 *
 * [191] Number of 1 Bits
 */

// @lc code=start
class Solution {
public:
    int hammingWeight(int n) {

        int res = 0;

        while (n > 0){
            if (n % 2 != 0 ){
                ++res;
            }
            n = n / 2;
        }

        return res;
        
    }
};
// @lc code=end

