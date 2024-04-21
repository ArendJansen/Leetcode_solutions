/*
 * @lc app=leetcode id=414 lang=cpp
 *
 * [414] Third Maximum Number
 */

// @lc code=start
#include <algorithm>
class Solution {
public:
    int thirdMax(vector<int>& nums) {

        std::vector<int> maxes;

        for (int i = 0; i < nums.size(); ++i){
            if (maxes.size() < 3 &&
                std::find(maxes.begin(), maxes.end(), nums[i]) == maxes.end()){
                maxes.push_back(nums[i]);
                std::sort(maxes.begin(), maxes.end());
            }
            else if (nums[i] > maxes[0] &&
                    std::find(maxes.begin(), maxes.end(), nums[i]) == maxes.end() ){
                maxes.push_back(nums[i]);
                std::sort(maxes.begin(), maxes.end());
                maxes.erase(maxes.begin());
            }
        }
        if (maxes.size() < 3 ){
            return maxes.back();
        }
        return maxes[0];
        
    }
};
// @lc code=end

