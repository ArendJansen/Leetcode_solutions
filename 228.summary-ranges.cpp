/*
 * @lc app=leetcode id=228 lang=cpp
 *
 * [228] Summary Ranges
 */

// @lc code=start
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {

        if (nums.size() == 0){
            return vector<string>();
        }
        string curr;
        vector<string> res;
        int l = nums[0];
        int r = nums[0];

        for (int i = 1;  i < nums.size(); ++i){
            if (nums[i] == nums[i-1] + 1){
                r = nums[i];
            }
            else {
                if (l == r){
                    res.push_back(std::to_string(l));
                }
                else {
                    curr = std::to_string(l) + "->" + std::to_string(r);
                    res.push_back(curr);
                }
                l = nums[i];
                r = nums[i];
            }
        }
        if (l == r){
            res.push_back(std::to_string(l));
        }
        else {
            curr = std::to_string(l) + "->" + std::to_string(r);
            res.push_back(curr);
        }

        return res;
    }
};
// @lc code=end

