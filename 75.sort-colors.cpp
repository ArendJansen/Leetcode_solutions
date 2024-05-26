/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int tmp =0, j = 0;
        for (int i = 0; i < nums.size(); ++i){
            if (i > 0 && nums[i] < nums[i-1]){
                j = i;
                while (j > 0 && nums[j] < nums[j-1]){
                    tmp = nums[j-1];
                    nums[j-1] = nums[j];
                    nums[j] = tmp;
                    --j;
                }

            }
        }
    }
};
// @lc code=end

