/*
 * @lc app=leetcode id=1493 lang=cpp
 *
 * [1493] Longest Subarray of 1's After Deleting One Element
 */

// @lc code=start

#include <vector>
using namespace std;


class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l = 0, r = 0, k = 0, count = 0, max = 0;

        for (int i = 0;  i < nums.size(); ++i){
            if (nums[i] == 0){
                ++k;
            }

            while (k > 1){
                if (nums[l] == 0){
                    --k;
                }
                ++l; 
            }
            max = std::max(max,i +1 -l - k);
        }
        if (max == nums.size()){
            --max;
        }
        return max;
    }

    //     while (r < nums.size()){
    //         if (nums[r] == 1){++count;}
    //         else {++k;}
    //         while (k > )
    //     }
    // }
};
// @lc code=end

