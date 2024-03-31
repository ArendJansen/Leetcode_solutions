/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 */

// @lc code=start
#include <vector>
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        std::vector<int> nums2 (n+1,-1);
        for (int i = 0; i < nums.size(); ++i){
            nums2[nums[i]] = nums[i];
        }
        for (int i = 0; i <= nums2.size(); ++i){
            if (nums2[i] == -1){
                return i;
            }
        }
        return 0;
        }
};
// @lc code=end

