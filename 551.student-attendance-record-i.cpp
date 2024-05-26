/*
 * @lc app=leetcode id=551 lang=cpp
 *
 * [551] Student Attendance Record I
 */

// @lc code=start
class Solution {
public:
    bool checkRecord(string s) {
        int a_count = 0, l_count = 0;

        for (int i = 0; i < s.length(); i++){
            if (s[i] == 'A'){
                ++a_count;
                l_count = 0;
                }
            else if (s[i] == 'L'){++l_count;}
            else{l_count = 0;}
            if (l_count == 3 || a_count == 2){return false;}
        }
        return true;
        
    }
};
// @lc code=end

