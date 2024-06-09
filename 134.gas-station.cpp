/*
 * @lc app=leetcode id=134 lang=cpp
 *
 * [134] Gas Station
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // int maxl =0, j = 1, p = -1;

        int sum = 0, j =0, tot = 0;

        std::vector<int> res(gas.size(),0);

        for (int i = 0;  i < gas.size(); ++i){
            res[i] = gas[i] - cost[i];
            tot += res[i];
        }
        

        if (tot < 0){
            return -1;
        }

        for (int i = 0;  i < res.size(); ++i){
            sum += res[i];
            if (sum < 0){
                j = i + 1;
                sum = 0;
            }
        }

        if (j  == res.size()){
            return -1;
        }
        return j;

        // for (int i = 0;  i < gas.size(); ++i){
        //     maxl = gas[i] - cost[i];
        //     if (maxl < j){
        //         j = maxl;
        //         p = i;
        //     }
        // }
        // int q = 0;
        // while(gas[p] - cost[p] < 0 && q < 10000){
        //     ++p;
        //     if (p == cost.size()){
        //         p = 0;
        //     }
        //     ++q;       
        // }
        // // ++p;
        // // if (p == cost.size()){
        // //     p =0;
        // // }
        // std::cout << "P equal to: " << p << "\n";

        // if (j == -1){
        //     return -1;
        // }

        // bool rloop = true;
        // int remain = 0, i = p;
        // while (rloop){
        //     remain += gas[i] - cost[i];
        //     if (remain  < 0){
        //         rloop = false;
        //         return -1;
        //     }
        //     ++i;
        //     if (i == gas.size()){
        //         i = 0;
        //     }
        //     if (i == p){
        //         rloop = false;
        //         return p;
        //     }

        // }
        // return -1;
    }
};
// @lc code=end

