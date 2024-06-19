/*
 * @lc app=leetcode id=2390 lang=cpp
 *
 * [2390] Removing Stars From a String
 */

// @lc code=start
#include <string>
#include <stack>
using namespace std;
class Solution {
public:
    string removeStars(string s) {
        std::string res;
        std::stack<char> stk;
        for (char x : s){
            if (x != '*'){
                stk.push(x);
            }
            else{
                if (!stk.empty()){
                    stk.pop();
                }
            }
        }
        if (stk.empty()){
            return "";
        }
        while (!stk.empty()){
            res += stk.top();
            stk.pop();
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

