/*
 * @lc app=leetcode id=435 lang=cpp
 *
 * [435] Non-overlapping Intervals
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        std::sort(
            intervals.begin(),
            intervals.end(),
            [](const vector<int> a , const vector<int> b){
                // if (a[0] != b[0]){
                //     return a[0] < b[0];
                // }
                // else{
                    return a[1] < b[1];
                // }
            });

            int l = 0, r =1, count = 0;

            while(r < intervals.size()){
                if (intervals[r][0] < intervals[l][1]){
                    // std::cout << "L:  " << "\n";
                    // std::cout << "[" << intervals[l][0] << "," << intervals[l][1] << "]\n";
                    // std::cout << "R:  " << "\n";
                    // std::cout << "[" << intervals[r][0] << "," << intervals[r][1] << "]\n";
                    // std::cout << "\n";
                    ++count;
                    ++r;
                }
                else{ 
                    l = r;
                    ++r;
                }
            }

            return count;
        

    }
};
// @lc code=end

