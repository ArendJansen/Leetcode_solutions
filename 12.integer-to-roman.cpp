/*
 * @lc app=leetcode id=12 lang=cpp
 *
 * [12] Integer to Roman
 */

// @lc code=start

#include <vector>
#include <utility>
#include <string>


std::pair<std::string,int> find_num(int x, const std::vector<std::pair<std::string, int>>& table2) {
    for (int i = 0; i < table2.size() - 1; i++) {
        int curr_num = table2[i].second;
        int next_num = table2[i + 1].second;

        if (x >= curr_num && x < next_num) {
            return table2[i];
        }
    }
    return table2[table2.size() - 1];

}

class Solution {
public:
    string intToRoman(int num) {
        std::vector<std::pair<std::string, int>> table = {
            {"I", 1},
            {"IV", 4},
            {"V", 5},
            {"IX", 9},
            {"X", 10},
            {"XL", 40},
            {"L", 50},
            {"XC", 90},
            {"C", 100},
            {"CD", 400},
            {"D", 500},
            {"CM", 900},
            {"M", 1000}
        };
        std::pair<std::string,int> tpair;
        std::string res;
        while(num > 0){
            tpair = find_num(num, table);
            res += tpair.first;
            num -= tpair.second;
        }
        return res;
        
    }
};
// @lc code=end

