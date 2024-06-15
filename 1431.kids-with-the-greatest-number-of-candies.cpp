/*
 * @lc app=leetcode id=1431 lang=cpp
 *
 * [1431] Kids With the Greatest Number of Candies
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        auto max_it = std::max_element(candies.begin(), candies.end());
        int max = *max_it;

        vector<bool> res(candies.size(), false);

        for (int i = 0;  i < res.size(); ++i){
            res[i] = candies[i] + extraCandies >= max ? true: false;
        }
        return res;
    }
};
// @lc code=end

