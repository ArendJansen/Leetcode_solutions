/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 */

// @lc code=start

#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::stack<std::pair<int,int>> stk;
        std::vector<int> res(temperatures.size(),0);

        for (int i = 0; i < temperatures.size(); ++i){
            while (!stk.empty() && temperatures[i] > stk.top().second){
                res[stk.top().first] =  i - stk.top().first;
                stk.pop();
            }
            stk.push(std::make_pair(i,temperatures[i]));
        }

        return res;
    }
};
// @lc code=end

