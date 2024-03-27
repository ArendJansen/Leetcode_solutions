/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

// @lc code=start
using namespace std;
#include <iostream>
#include <unordered_map>
#include <vector>

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        std::unordered_map<int, int> nums2;

        int maxValue = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            nums2[nums[i]]++;
        }
        for (const auto &pair : nums2)
        {
            if (pair.second > maxValue)
            {
                maxValue = pair.second;
            }
        }
        return maxValue > 1;
    }
};
// @lc code=end
