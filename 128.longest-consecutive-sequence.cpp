/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start
#include <iostream>

using namespace std;
#include <vector>
#include <map>
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int> lmap;

        for (int num : nums){
            ++lmap[num];
        }

        int curr = -INT_MAX;
        int count = 0, max =0;
        for (auto it = lmap.begin(); it != lmap.end(); ++it){
            if (curr == -INT_MAX){
                curr = it -> first;
                ++count;
            }
            else if (lmap.count(curr + 1 ) > 0){
                ++curr;
                ++count;
            }
            else {
                curr = it -> first;
                count = 1;
            }

            max = std::max(max,count);

        }

        return max;
    }
};
// @lc code=end

