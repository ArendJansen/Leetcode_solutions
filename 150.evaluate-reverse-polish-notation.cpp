/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */

// @lc code=start
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        stack<string> stk;

        int a = 0, b =0 ;
        
        for (string tok : tokens){
            if (tok == "+"){
                b = std::stoi(stk.top());
                stk.pop();
                a = std::stoi(stk.top());
                stk.pop();
                stk.push(std::to_string(a + b));
            }
            else if (tok == "-"){
                b = std::stoi(stk.top());
                stk.pop();
                a = std::stoi(stk.top());
                stk.pop();
                stk.push(std::to_string(a - b));
            }
            else if (tok == "*"){
                b = std::stoi(stk.top());
                stk.pop();
                a = std::stoi(stk.top());
                stk.pop();
                stk.push(std::to_string(a * b));
            }
            else if (tok == "/"){
                b = std::stoi(stk.top());
                stk.pop();
                a = std::stoi(stk.top());
                stk.pop();
                stk.push(std::to_string(a / b));
            }
            else {
                stk.push(tok);
            }

        }

        return std::stoi(stk.top());
    }
};
// @lc code=end

