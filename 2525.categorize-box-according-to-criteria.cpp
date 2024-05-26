/*
 * @lc app=leetcode id=2525 lang=cpp
 *
 * [2525] Categorize Box According to Criteria
 */

// @lc code=start
class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        bool bulky = false;
        long long volume = width;
        volume *= height;
        volume *= length;
        if (length >= 10000 || width >= 10000 || 
            height >= 10000 || volume >= 1000000000){
                bulky = true;
        }

        bool heavy = mass >= 100 ? true : false;

        if (heavy && bulky){
            return "Both";
        }
        if (bulky){
            return "Bulky";
        }
        if (heavy){return "Heavy";}
        return "Neither";
    }
};
// @lc code=end

