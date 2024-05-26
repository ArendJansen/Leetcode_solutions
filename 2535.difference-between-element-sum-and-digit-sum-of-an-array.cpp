/*
 * @lc app=leetcode id=2535 lang=cpp
 *
 * [2535] Difference Between Element Sum and Digit Sum of an Array
 */

// @lc code=start
class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int digits = 0, elements = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            elements += nums[i];

            while (nums[i] > 0){
                digits += nums[i] % 10;
                nums[i] /= 10;
            }
        }

        return std::abs(digits - elements);
        
    }
};
// @lc code=end

