/*
 * @lc app=leetcode id=2751 lang=cpp
 *
 * [2751] Robot Collisions
 */

// @lc code=start

#include <vector>
#include <utility>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;


class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
    std::vector<std::pair<int, std::pair<int,int>>> health_with_index(healths.size());
    std::vector<std::pair<int, int>> dir_with_index(healths.size());

    // Populate the vector of pairs
    for (int i = 0; i < healths.size(); ++i) {
        health_with_index[i] = {positions[i],{healths[i],i }};
        dir_with_index[i] = {positions[i], directions[i]};
    }

    // Sort the vector of pairs based on the first element (position)
    std::sort(health_with_index.begin(), health_with_index.end());
    std::sort(dir_with_index.begin(), dir_with_index.end());

;
    string sorted_dirs;
    for (const auto& pair : dir_with_index) {
        sorted_dirs.push_back(pair.second);
    }    
    
    directions = sorted_dirs;
    
    std::stack<std::pair<int, std::pair<int,int>>> stk;
    bool add = true;

    for (int i = 0;  i < positions.size(); ++i){
        add = true;
        if (directions[i] == 'L'){
            while(!stk.empty()){
                if (stk.top().second.first < 0){
                    break;
                }
                else if (stk.top().second.first > 0 && stk.top().second.first == health_with_index[i].second.first){
                    stk.pop();
                    add = false;
                    break;
                }
                else if (stk.top().second.first > 0 && stk.top().second.first > health_with_index[i].second.first){
                    add = false;
                    --stk.top().second.first;
                    if (stk.top().second.first == 0){
                        stk.pop();
                    }
                    break;
                }
                else {
                    --health_with_index[i].second.first;
                    if (health_with_index[i].second.first == 0){
                        add = false;
                        break;
                    }
                    stk.pop();
                }
            }
            if (add){
                health_with_index[i].second.first *= -1;
                stk.push(health_with_index[i]);
            }
        }
        else {
            stk.push(health_with_index[i]);

        }
    }

    vector<std::pair<int,std::pair<int,int>>> res;

    while(!stk.empty()){
        res.push_back(stk.top());
        stk.pop();
    }

    std::sort(res.begin(), res.end(), [](const auto& a, const auto& b) {
    return a.second.second < b.second.second;});

    vector<int> res2;

    for (const auto& pair : res){
        res2.push_back(std::abs(pair.second.first));
    } 

    return res2;

    }
};
// @lc code=end

