/*
 * @lc app=leetcode id=561 lang=cpp
 *
 * [561] Array Partition
 */

// @lc code=start
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {

        int sum = 0;
        std::sort(nums.begin(),nums.end());

        for (int i = 0;  i < nums.size() - 1; i+=2){
            sum += nums[i];
        }

        return sum;
        
    }
};
// @lc code=end

