/*
 * @lc app=leetcode id=190 lang=cpp
 *
 * [190] Reverse Bits
 */

// @lc code=start
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t rev_num = 0;

        for (int i = 0; i < 32; ++i) {
            rev_num = (rev_num << 1) | (n & 1);
            n >>= 1;
        }

        return rev_num;

    
        
    }
};
// @lc code=end

