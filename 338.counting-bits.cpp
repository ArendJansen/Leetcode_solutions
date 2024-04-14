/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 */

// @lc code=start
class Solution {
public:
    vector<int> countBits(int n) {
        std::vector<int> res;

        for (int i = 0; i <= n; ++i){
            res.push_back(__builtin_popcount(i));
        }
        return res;
    }
};
// @lc code=end

