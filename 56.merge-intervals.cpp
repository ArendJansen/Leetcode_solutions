/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        // if (intervals.size() <= 1){
        //     return intervals;
        // }

        std::sort(
            intervals.begin(), 
            intervals.end(),
            [](const std::vector<int>& a, const std::vector<int>& b){
                return a[0] < b[0];
            });

        for (auto it = intervals.begin(); it != intervals.end() -1; ) {
            if ( (*(it+1))[0] <= (*it)[1] ) {
                (*it)[1] = std::max((*it)[1], (*(it+1))[1]);
                ++it;
                it = intervals.erase(it);
                --it;
            } 
            else {
                ++it;
            }
        }
        return intervals;
        
    }
};
// @lc code=end

