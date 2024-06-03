/*
 * @lc app=leetcode id=93 lang=cpp
 *
 * [93] Restore IP Addresses
 */

// @lc code=start

#include <vector>
#include <string>

using namespace std;
using namespace std;
bool isValid(string & s){
    int l =0, r = 0;
    long long num = 0;
    int count = 0;
    string sub_s;
    while (r < s.length()){
        if (count > 4){
            return false;
        }
        if (s[r] == '.'){
            count = 0;
            sub_s = s.substr(l,r -l );
            std::cout << "Substr: " << sub_s << "\n";
            if (sub_s.length() > 0){
                num = std::stoll(sub_s);
                if (sub_s.length() > 1 && sub_s[0] == '0'){
                    return false;
                }
                if (num > 255){
                    return false;
                }
            }
            l = r + 1;
            ++r;
        }
        else {
            ++r;
            ++count;
        }
     }
    sub_s = s.substr(l,r - l);
    if (sub_s.length() > 0){
        num = std::stoll(sub_s);
        if (sub_s.length() > 1 && sub_s[0] == '0'){
            return false;
        }
        if (num > 255){
            return false;
        }
    }
    return true;
}

int countNum(std::string & s){
    int count = 0;
    for (int i = 0;  i < s.length(); ++i){
        if (s[i] != '.'){
            ++count;
        }
    }
    return count;
}

void Solve(string & s, string & state, unordered_set<string> & sols, int curr, int nint){
    if (countNum(state) == s.length() && isValid(state) && nint == 4){
        sols.insert(state);
        return;
    }
    else if (countNum(state) == s.length()){
        return;
    }
    else if (nint > 4){
        return;
    }

    if (state.back() == '.'){
        state.push_back(s[curr]);
        Solve(s,state,sols,curr +1,nint);
        state.pop_back();     
    }
    else if (state.back() != '.'){
        state.push_back(s[curr]);
        Solve(s,state,sols,curr +1,nint);
        state.pop_back();      
        state.push_back('.');
        Solve(s,state,sols,curr,nint +1);
        state.pop_back();
    }
}
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        std::unordered_set<string> res;
        string state(1,s[0]);
        Solve(s,state,res,1,1);

        return vector<string>(res.begin(), res.end());
    }
};
// @lc code=end

