/*
 * @lc app=leetcode id=485 lang=cpp
 *
 * [485] Max Consecutive Ones
 */

// @lc code=start
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int max_c = 0;

        for (int num : nums){
            if (num == 1){
                ++count;
                if (count > max_c){
                    max_c  = count;
                }
            } 
            else {
                count = 0;
            }
        }
        return max_c;
    }
};
// @lc code=end

