/*
 * @lc app=leetcode id=495 lang=cpp
 *
 * [495] Teemo Attacking
 */

// @lc code=start
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int count = duration;


        for (int i = 0; i < timeSeries.size() -1; ++i){

            count += std::min(duration, timeSeries[i+1] - timeSeries[i]);
        }
        return count;

    }
};
// @lc code=end

