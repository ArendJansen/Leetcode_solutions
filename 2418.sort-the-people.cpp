/*
 * @lc app=leetcode id=2418 lang=cpp
 *
 * [2418] Sort the People
 */

// @lc code=start
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool compare(int a, int b, const std::vector<int>& ref_vec) {
        return ref_vec[a] < ref_vec[b];
    }
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {

        std::sort(
            names.begin(),
            names.end(),
            [](const int & a, const int & b){
                return (a,b, heights);
            }
        )    
        return names;
    }
};
// @lc code=end

