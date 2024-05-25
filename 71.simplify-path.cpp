/*
 * @lc app=leetcode id=71 lang=cpp
 *
 * [71] Simplify Path
 */

// @lc code=start
#include <stack>
#include <string>
class Solution {
public:
    string simplifyPath(string path) {
        std::stack<std::string> stk;
        std::string str, tmp;
        bool non_slash =false;

        for (int i = 0; i < path.length(); ++i){
            if (str.empty()){
                str += path[i];
            } 
            else if (path[i] != '/'){
                non_slash = true;
                str += path[i];
            }
            else if (!non_slash && path[i] == '/'){
                
            }
            else {
                non_slash = false;
                if (str == "/.." && !stk.empty()){
                    stk.pop();
                    str = "/";
                } 
                else if (str == "/.." && stk.empty()){
                    str = "/";
                }
                else if (str == "/."){
                    str = "/";
                }
                else {
                    stk.push(str);
                    str = "/";
                }
            }
        }

        if (!str.empty()){
            if (str == "/.." && ! stk.empty()){
                stk.pop();
                str.clear();
            }
            else if (str == "/.." && stk.empty()){
                str.clear();
            }
            else if (str == "/."){
                str.clear();
            }
            else {
                stk.push(str);
                str.clear();
            }
        }

        while (!stk.empty()){
            tmp = stk.top();
            std::reverse(tmp.begin(),tmp.end());
            str += tmp;
            stk.pop();
        }

        std::reverse(str.begin(),str.end());
        if (str.length() > 1 && str[str.length() -1 ] == '/'){
            str.pop_back();
        }

        if (str.empty()){
            str = "/";
        }

        return str;
    }
};
// @lc code=end

