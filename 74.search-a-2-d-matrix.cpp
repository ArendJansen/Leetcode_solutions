/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int nrow = matrix.size(), ncol = matrix[0].size();
        int l = 0, r = nrow * ncol - 1, m = 0;
        int mrow = 0 , mcol = 0;
        while (l <= r){
            m = l + (r - l) /2;
            mrow = m / ncol;
            mcol = m % ncol;
            if (matrix[mrow][mcol] == target){
                return true;
            }
            else if (matrix[mrow][mcol] > target){
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }

        return false;
    }
};
// @lc code=end

