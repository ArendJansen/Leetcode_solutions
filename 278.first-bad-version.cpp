/*
 * @lc app=leetcode id=278 lang=cpp
 *
 * [278] First Bad Version
 */

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 0, right = n, middle = 0, res = n;
        while (left <= right){
            middle = left + (right - left) / 2; 
            if (isBadVersion(middle)){
                res = middle;
                right  = middle - 1;
            }
            else {
                left = middle + 1;
            }
        }

        return res;

        
    }
};
// @lc code=end

