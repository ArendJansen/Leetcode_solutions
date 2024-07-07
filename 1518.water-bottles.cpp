/*
 * @lc app=leetcode id=1518 lang=cpp
 *
 * [1518] Water Bottles
 */

// @lc code=start
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int res = 0;
        int empty =0;
        
        while (numBottles > 0){
            res += numBottles;
            empty += numBottles;
            numBottles = empty / numExchange;
            empty = empty % numExchange;

        }
        return res;
    }
};
// @lc code=end

