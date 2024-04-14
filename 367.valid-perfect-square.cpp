/*
 * @lc app=leetcode id=367 lang=cpp
 *
 * [367] Valid Perfect Square
 */

// @lc code=start
class Solution {
public:
    bool isPerfectSquare(int num) {

        if (num == 1){
            return true;
        }

        int left = 0;
        int right = num / 2;

        while (left <= right){
            long middle = left + (right - left )/2;

            if (middle * middle == num){
                return true;
            }
            else if (middle * middle < num){
                left = middle + 1;
            }
            else{
                right = middle - 1;
            }
        }
        return false;
        
        
    }
};
// @lc code=end

