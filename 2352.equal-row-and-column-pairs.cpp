/*
 * @lc app=leetcode id=2352 lang=cpp
 *
 * [2352] Equal Row and Column Pairs
 */

// @lc code=start
#include <vector>
#include <string>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {

        int res = 0;

        std::unordered_map<std::string, int> lmap;
        std::unordered_map<std::string, int> rmap;
        std::string tmp;

        for (int i = 0;  i < grid.size(); ++i){
            for (int j = 0;  j < grid[0].size(); ++j){
                tmp += std::to_string(grid[i][j]);
                tmp += '-';
            }
            lmap[tmp]++;
            tmp.clear();
        }
        for (int j = 0;  j < grid[0].size(); ++j){
            for (int i = 0;  i < grid.size(); ++i){
                tmp += std::to_string(grid[i][j]);
                tmp += '-';
            }
            rmap[tmp]++;
            tmp.clear();
        }

        for (auto it = lmap.begin(); it != lmap.end(); ++it){
            for (auto it2 = rmap.begin(); it2 != rmap.end(); ++it2){
                if (it -> first == it2 -> first){
                    res += it -> second * it2 -> second;

                }
            }
        }
        return res;        
    }
};
// @lc code=end

