/*
 * @lc app=leetcode id=2462 lang=cpp
 *
 * [2462] Total Cost to Hire K Workers
 */

// @lc code=start
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> lque;
    std::priority_queue<int, std::vector<int>, std::greater<int>> rque;
        int l = 0, r = costs.size() -1 , count = 0, pick = 0;
        long long sum =0;

        while (l < r && count < candidates){
            lque.push(costs[l]);
            rque.push(costs[r]);
            ++count;
            ++l;
            --r;
        }
        if (l == r && count < candidates){
            lque.push(costs[l]);
            ++l;
        }

        while (pick < k){

            if (lque.size() == 0 && rque.size() > 0){
                sum += rque.top();
                rque.pop();
            }
            else if (lque.size() > 0 && rque.size() == 0){
                sum += lque.top();
                lque.pop();
            }
            else if (lque.top() <= rque.top()){
                sum += lque.top();
                lque.pop();
            }
            else {
                sum += rque.top();
                rque.pop();
            }

            ++pick;

            if (lque.size() < candidates && l <= r){
                lque.push(costs[l]);
                ++l;
            }
            if (rque.size() < candidates && l <= r){
                rque.push(costs[r]);
                --r;
            }
        }

        return sum;
    }
};
// @lc code=end

