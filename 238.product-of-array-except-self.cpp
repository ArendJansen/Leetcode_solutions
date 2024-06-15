/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zero_count = 0;
        int zero_idx;

        vector<int> prefix(nums.size(),0);
        prefix[0] = nums[0];
        if (nums[0] == 0){
            ++zero_count;
            prefix[0] = 1;
            zero_idx = 0;
        }
        for (int i = 1;  i < prefix.size(); ++i){
            if (nums[i] != 0){
                prefix[i] = prefix[i-1] * nums[i];
            }
            else {
                prefix[i] = prefix[i-1] * 1;
                ++zero_count;
                zero_idx = i;
            }
        }

        if (zero_count == 0){
            for (int i = 0;  i < prefix.size(); ++i){
                prefix[i] = prefix[prefix.size() -1] / nums[i];  
            }
            return prefix;
        }
        else if (zero_count == 1){
            for (int i = 0;  i < prefix.size(); ++i){
                if (i == zero_idx){
                    prefix[i] = prefix[prefix.size() -1];
                }
                else {
                    prefix[i] = 0;
                }
            }
        }
        else {
            return vector<int>(prefix.size(),0);
        }
        return prefix;
        
    }
};
// @lc code=end

