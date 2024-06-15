/*
 * @lc app=leetcode id=334 lang=cpp
 *
 * [334] Increasing Triplet Subsequence
 */

// @lc code=start
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {

        if (nums.size() < 3){
            return false;
        }

        int l = nums[0], m = INT_MAX;

        for (int i = 1; i < nums.size(); ++i){
            if (nums[i] < l){
                l = nums[i];
            } else if (nums[i] > l ){
                m = std::min(m,nums[i]);
            }
            if (nums[i] > m){return true;}
        }
        return false;
    }
};
// @lc code=end

