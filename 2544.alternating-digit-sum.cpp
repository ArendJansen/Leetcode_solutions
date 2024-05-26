/*
 * @lc app=leetcode id=2544 lang=cpp
 *
 * [2544] Alternating Digit Sum
 */

// @lc code=start
#include<vector>
class Solution {
public:
    int alternateDigitSum(int n) {

        std::vector<int> nums;
        int res = 0, sign = 1;

        while (n > 0){
                nums.push_back(n % 10);
            n /= 10;
        }

        for (int i = nums.size() -1; i >= 0; --i)
        {
            res += sign * nums[i];
            sign *= -1;
        }
        return res;
        
        
    }
};
// @lc code=end

