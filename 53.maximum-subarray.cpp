/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {


        
        int r = 0, cs = 0, max = -INT_MAX;
        while (r < nums.size()){
            cs += nums[r];
            max = std::max(max,cs);
            if (cs < 0){
                cs = 0;
            }
            ++r;
        }
        return max;
    }
};
// @lc code=end

