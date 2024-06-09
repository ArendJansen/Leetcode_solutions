/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 */

// @lc code=start

using namespace std;
#include <vector>
#include <algorithm>

// int Buy(int day, const vector<int> & prices){
//     if (day >= prices.size()){
//         return 0;
//     }
//     int buying = Sell(day +1 , prices) - prices[day];
//     int not_buying = Buy(day+1, prices);

//     return std::max(buying,not_buying);
// }

// int Sell(int day, const vector<int> & prices){
//     if (day >= prices.size()){
//         return 0;
//     }
//     int selling = prices[day] + Buy(day+ 2,prices);
//     int not_selling = Sell(day + 1, prices);

//     return std::max(selling,not_selling);
// }
class Solution {
public:
    int Buy(int day, const vector<int> & prices, vector<int> & buy_cache, vector<int> & sell_cache){
        if (day >= prices.size()){
            return 0;
        }
        if (buy_cache[day] != -2000){
            return buy_cache[day];
        }
        int buying = Sell(day +1 , prices, buy_cache,sell_cache) - prices[day];
        int not_buying = Buy(day+1, prices, buy_cache, sell_cache);

        buy_cache[day] = std::max(buying,not_buying);

        return std::max(buying,not_buying);
    };

    int Sell(int day, const vector<int> & prices, vector<int> & buy_cache, vector<int> & sell_cache){
        if (day >= prices.size()){
            return 0;
        }
        if (sell_cache[day] != -2000){
            return sell_cache[day];
        }
        int selling = prices[day] + Buy(day+ 2,prices, buy_cache,sell_cache);
        int not_selling = Sell(day + 1, prices, buy_cache, sell_cache);

        sell_cache[day] = std::max(selling,not_selling);

        return std::max(selling,not_selling);
    };
    int maxProfit(vector<int>& prices) {

        vector<int> buy_cache(prices.size(),-2000);
        vector<int> sell_cache(prices.size(),-2000);

        return Buy(0,prices, buy_cache, sell_cache);
        
    }
};
// @lc code=end

