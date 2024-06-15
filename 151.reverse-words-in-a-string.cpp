/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 */

// @lc code=start
#include <string>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        int l = 0, r = 0;
        bool at_whitespace = false;
        std::stack<std::string> stk;

        if (s[0] == ' '){
            at_whitespace = true;
        }

        while(r < s.length()){
            if (s[r] != ' ' && ! at_whitespace){
                ++r;
            }
            else if (s[r] == ' ' && !at_whitespace){
                stk.push(s.substr(l,r-l));
                at_whitespace = true;
            }
            else if (s[r] == ' ' && at_whitespace){
                ++r;
            }
            else if (s[r] != ' ' && at_whitespace){
                l = r;
                ++r;
                at_whitespace = false;
            }
        }

        if (!at_whitespace){
            stk.push(s.substr(l,r-l));
        }
        std::string res;
        while (!stk.empty()){
            res += stk.top();
            res += ' ';
            stk.pop();
        }
        res.pop_back();
        return res;
    }
};
// @lc code=end

