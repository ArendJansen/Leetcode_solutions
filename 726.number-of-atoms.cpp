/*
 * @lc app=leetcode id=726 lang=cpp
 *
 * [726] Number of Atoms
 */

// @lc code=start
#include <string>
#include <stack>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;


class Solution {
public:
    bool is_number(char x){
        return x == '1' ||
            x == '2' ||
            x == '3' ||
            x == '4' ||
            x == '5' ||
            x == '6' ||
            x == '7' ||
            x == '8' ||
            x == '9' ||
            x == '0'; 
    }
    string countOfAtoms(string formula) {

        formula += "@";
        
        stack<char> stk;
        string tmp;
        string num_str;
        bool get_count = false;
        int count = 0;
                
        for (char x: formula){
            if (get_count){
                if (is_number(x)){
                    num_str += x;
                }
                else {
                    if (num_str.empty()){
                        for (char y: tmp){
                            stk.push(y);
                        }
                    }
                    else {
                        count = std::stoi(num_str);
                        while (count > 0){
                            for (char y: tmp){
                                stk.push(y);
                            }       
                            --count;
                        }
                    }
                    tmp.clear();
                    num_str.clear();
                    
                    if (x == ')'){
                        while (!stk.empty() && stk.top() != '('){
                            tmp += stk.top();
                            stk.pop();
                        }
                        stk.pop();
                        std::reverse(tmp.begin(), tmp.end());
                        get_count = true;                    
                    }
                    else{
                        stk.push(x);
                        get_count = false;
                    }
                }
                
            }
            else if (x != ')'){
                stk.push(x);
            }
            else if (x == ')'){
                while (!stk.empty() && stk.top() != '('){
                    tmp += stk.top();
                    stk.pop();
                }
                stk.pop();
                std::reverse(tmp.begin(), tmp.end());
                get_count = true;
            }
        }
        
        string tmp2;

        while(!stk.empty()){
            tmp2 += stk.top();
            stk.pop();
        }
        
        std::reverse(tmp2.begin(), tmp2.end());
                
        map<string,int> lmap;
        tmp.clear();
        num_str.clear();
        get_count = false;
        bool get_upper = false;
        count = 0;
        
        for (char x: tmp2){
            if (std::isupper(x) && !get_upper){
                tmp += x;
                get_upper = true;
            }
            else if (std::islower(x)){
                tmp += x;
            }
            else if (std::isupper(x) && get_upper){
                if (num_str.empty()){
                    ++lmap[tmp];
                }
                else {
                    count = std::stoi(num_str);
                    lmap[tmp] += count;
                }
                tmp.clear();
                num_str.clear();
                tmp += x;
                get_upper = true;
            }
            else if (is_number(x)){
                num_str += x;
            }
            else if (x == '@'){
                if (num_str.empty()){
                    ++lmap[tmp];
                }
                else {
                    count = std::stoi(num_str);
                    lmap[tmp] += count;
                }
                tmp.clear();
                num_str.clear();
                break;
            }
        }
        string res; 
        for (const auto& pair : lmap){
            res += pair.first;
            if (pair.second > 1){
                res += std::to_string(pair.second);
            }
        }
        return res;
        
    }
};
// @lc code=end

