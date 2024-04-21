/*
 * @lc app=leetcode id=441 lang=cpp
 *
 * [441] Arranging Coins
 */

// @lc code=start
class Solution {
public:
    int arrangeCoins(int n) {
        long long  x = 8LL * n;
        int y = (std::sqrt(x + 1) -1) /2 ;
        return y;
    }
};
// @lc code=end

