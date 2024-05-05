/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int r = 1;
        int max_prof = 0;
        int curr_prof =0;
        int tot_prof = 0;

        while (r < prices.size()){
            if (prices[r] <= prices[l]){
                l = r;
                r += 1;
            } 
            else if (prices[r] > prices[l]){
                max_prof = std::max(curr_prof,  prices[r] - prices[l]);
                if (prices[r] - prices[r-1] + curr_prof > max_prof ){
                    tot_prof += curr_prof;
                    curr_prof = prices[r] - prices[r-1];
                    l = r -1;
                    r = r + 1;
                } 
                else {
                    curr_prof = max_prof;
                    r += 1;
                }
            }
        }
        tot_prof += curr_prof;
        return tot_prof;

    }
};
// @lc code=end

