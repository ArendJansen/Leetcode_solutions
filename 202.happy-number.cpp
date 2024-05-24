/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 */

// @lc code=start
#include <unordered_set>

class Solution {
public:
    bool isHappy(int n) {
        int res = 0;
        std::unordered_set<int> seen;

        while (seen.find(n) == seen.end()){
            seen.insert(n);
            while (n > 0){
                res += ((n % 10) * (n % 10));
                n = n / 10;
            }
            if (res == 1){
                return true;
            }
            n = res;
            res = 0;

        }
        return false;
    }
};
// @lc code=end

