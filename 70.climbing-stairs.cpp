/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
#include <map>
class Solution {
public:
    int climbStairs(int n) {

        int res =0;
        int i = 2;
        int n1= 2;
        int n2 = 1;

        if (n <= 2){
            return n;
        }
        else{
            while(i < n){
                res = n1 + n2;
                n2 = n1;
                n1 = res;
                ++i;
            }
            return res;
        }

        
    }
};
// @lc code=end

