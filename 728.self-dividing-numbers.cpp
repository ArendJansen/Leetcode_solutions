/*
 * @lc app=leetcode id=728 lang=cpp
 *
 * [728] Self Dividing Numbers
 */

// @lc code=start

#include <vector>
#include <string> 
using namespace std;


class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {

        vector<int> res;
        int num = 0;
        int divisor = 0;
        bool add = true;
        for (int i = left; i <= right; ++i){
            num = i;
            add =true;
            while(num > 0){
                divisor = num % 10;
                if (divisor == 0){
                    add = false;
                    break;
                }
                if (i % divisor != 0){
                    add = false;
                    break;
                }
                num /= 10;
            }
            if (add){
                res.push_back(i);
            }
        }
        return res;
    }
};
// @lc code=end

