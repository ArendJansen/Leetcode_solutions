/*
 * @lc app=leetcode id=434 lang=cpp
 *
 * [434] Number of Segments in a String
 */

// @lc code=start
class Solution {
public:
    int countSegments(string s) {
        
        bool empty = true;
        int counter = 0;
        for (char x : s){
            if (x == ' '){
                empty = true;
            }
            else if (x != ' ' && empty) {
                ++counter;
                empty = false;
            }
        }
        return counter;
    }
};
// @lc code=end

