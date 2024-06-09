/*
 * @lc app=leetcode id=714 lang=cpp
 *
 * [714] Best Time to Buy and Sell Stock with Transaction Fee
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {

        int pos = -prices[0];
        int profit = 0;
        for (int i = 1;  i < prices.size(); ++i){
            pos = std::max(pos,profit - prices[i]);
            profit = std::max(profit,pos + prices[i] - fee);
            
        }
        return profit;
        // int l = 0, r = 1, tot_prof = 0, loc_prof = 0;

        // while (r < prices.size()){
        //     std::cout << "L equal: " << l << "\n";
        //     std::cout << "R equal: " << r << "\n";
        //     std::cout << "Prices[L]: " << prices[l] << "\n";
        //     std::cout << "Prices[R]: " << prices[r] << "\n";
        //     std::cout << "Local profit: " << loc_prof << "\n";
        //     std::cout << "Total profit: " << tot_prof << "\n\n";
        //     if (prices[r] > prices[l]){
        //         loc_prof = std::max(loc_prof,prices[r] - prices[l] - fee);
        //     }

        //     if (prices[l] > prices[r]){
        //         tot_prof += loc_prof;
        //         loc_prof = 0;
        //         l = r;
        //     }
        //     else if (prices[r] < prices[r-1]){
        //         if (loc_prof > 0 && prices[r-1] - prices[r] >= fee ){
        //             tot_prof += loc_prof;
        //             loc_prof = 0;
        //             l = r;
        //         } 

        //     }
        //     ++r;
        // }

        // return tot_prof + loc_prof;
    }
};
// @lc code=end

