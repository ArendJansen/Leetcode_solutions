/*
 * @lc app=leetcode id=492 lang=cpp
 *
 * [492] Construct the Rectangle
 */

// @lc code=start
#include <vector>
class Solution {
public:
    vector<int> constructRectangle(int area) {
        
        for (int i = 1; i <= area / 2; ++i){
            if (area % i == 0 &&  (area / i) <= i){
                return std::vector{i, area / i};
            }
        }
        return std::vector{area,1};
    }
};
// @lc code=end

