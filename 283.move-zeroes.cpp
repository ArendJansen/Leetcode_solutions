/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int zero_index = 0;
        for (int i = 0; i < n; ++i){
            if (nums[i] != 0){
                nums[zero_index] = nums[i];
                ++zero_index;
            }
        }
        while (zero_index < n){
            nums[zero_index] = 0;
            ++zero_index;
        }
        
    }
};
// @lc code=end

