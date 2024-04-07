/*
 * @lc app=leetcode id=374 lang=cpp
 *
 * [374] Guess Number Higher or Lower
 */

// @lc code=start
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int left = 1;
        int right = n;

        while (right >= left){
            int npick = left + (right - left)/2;
            int res = guess(npick);

            if (res == 0){
                return npick;
            }
            else if (res == -1){
                right = npick -1;
            } 
            else {
                left = npick + 1;
            }
        }
        return 0;
        
    }
};
// @lc code=end

