/*
 * @lc app=leetcode id=1071 lang=cpp
 *
 * [1071] Greatest Common Divisor of Strings
 */

// @lc code=start
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int l1 = str1.length(), l2 = str2.length();
        std::string tmp, tmp2;

        if (l1 >= l2){
            if (str1.substr(0,l2) != str2){
                return "";
            }
            tmp = str2;
            
            while(!tmp.empty()){
                if (l1 % tmp.length() != 0 || l2 % tmp.length() != 0){
                    tmp.pop_back();
                    continue;
                }
                int division = l1 / tmp.length();
                while (division > 0){
                    tmp2 += tmp;
                    --division;
                }
                if (tmp2 == str1){
                    return tmp;
                }
                tmp.pop_back();
                tmp2.clear();
            }
        }
        else if (l2 > l1){
            if (str2.substr(0,l1) != str1){
                return "";
            }
            tmp = str1;
            
            while(!tmp.empty()){
                if (l2 % tmp.length() != 0 || l1 % tmp.length() != 0){
                    tmp.pop_back();
                    continue;
                }
                int division = l2 / tmp.length();
                while (division > 0){
                    tmp2 += tmp;
                    --division;
                }
                if (tmp2 == str2){
                    return tmp;
                }
                tmp.pop_back();
                tmp2.clear();
            }

        }
        return tmp;
    }
};
// @lc code=end

