/*
 * @lc app=leetcode id=452 lang=cpp
 *
 * [452] Minimum Number of Arrows to Burst Balloons
 */

// @lc code=start

using namespace std;

#include <vector>
#include <algorithm>

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int count = 1;
        std::sort(
            points.begin(), 
            points.end(), 
            [](const std::vector<int>& a, const std::vector<int>& b) { return a[1] < b[1]; }
        );

        int tmp = points[0][1];

        for (int i = 1;  i < points.size(); ++i){
            if (points[i][0] > tmp){
                ++count;
                tmp = points[i][1];
            }
        }

        return count;
        
    }
};
// @lc code=end

