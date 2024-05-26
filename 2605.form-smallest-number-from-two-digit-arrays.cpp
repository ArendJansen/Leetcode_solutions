/*
 * @lc app=leetcode id=2605 lang=cpp
 *
 * [2605] Form Smallest Number From Two Digit Arrays
 */

// @lc code=start
#include <unordered_map>

class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        int min_a = 9, min_b =9;
        int res = 10;
        std::unordered_map<int,int> lmap;

        for (size_t i = 0; i < nums1.size(); i++)
        {
            min_a = nums1[i] < min_a ? nums1[i] : min_a;
            ++lmap[nums1[i]];
        }
        for (size_t i = 0; i < nums2.size(); i++)
        {
            min_b = nums2[i] < min_b ? nums2[i] : min_b;
            ++lmap[nums2[i]];
        }
        
        for (const auto & pair : lmap){
            if (pair.second > 1 && pair.first < res){
                res = pair.first;
            }
        }

        if (res != 10){return res;}

        res = min_a < min_b ? min_a * 10 + min_b : min_b * 10 + min_a;
        return res;
        
        
    }
};
// @lc code=end

