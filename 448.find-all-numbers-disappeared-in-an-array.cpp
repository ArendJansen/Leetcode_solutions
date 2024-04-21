/*
 * @lc app=leetcode id=448 lang=cpp
 *
 * [448] Find All Numbers Disappeared in an Array
 */

// @lc code=start
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for (int num : nums){
            int n = abs(num) -1;
            nums[n] = - 1 * abs(nums[n]);
        }

        std::vector<int> missing;

        for (int i = 0; i < nums.size(); ++i)
        if (nums[i] > 0){
            missing.push_back(i + 1);
        }
        return missing;
    }
};
// @lc code=end

