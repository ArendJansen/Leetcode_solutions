/*
 * @lc app=leetcode id=724 lang=cpp
 *
 * [724] Find Pivot Index
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        std::vector<int> res(nums.size() + 1, 0);

        for (int i = 1; i < res.size(); ++i){
            res[i] = res[i-1] + nums[i-1];
        }

        for (int i = 0;  i < res.size(); ++i){
            std::cout << res[i] << "\n";
        }
        // res.insert(res.begin(),0);
        int x = res[res.size() - 1];
        // if (x % 2 != 0){
        //     return -1;
        // }

        for (int i = 1;  i < res.size(); ++i){
            if ((x - res[i]) == res[i-1]){
                return i-1;
            }
        }

        return -1;

    }
};
// @lc code=end

