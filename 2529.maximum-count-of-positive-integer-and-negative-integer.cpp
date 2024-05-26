/*
 * @lc app=leetcode id=2529 lang=cpp
 *
 * [2529] Maximum Count of Positive Integer and Negative Integer
 */

// @lc code=start
class Solution {
public:
    int maximumCount(vector<int>& nums) {

        int posc = 0, negc = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] > 0){
                ++posc;
            }
            else if (nums[i] < 0){
                ++negc;
            }
        }

        return std::max(posc,negc);
        
        
    }
};
// @lc code=end

