/*
 * @lc app=leetcode id=412 lang=cpp
 *
 * [412] Fizz Buzz
 */

// @lc code=start
#include <string>
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        std::vector<std::string> res;

        for (std::size_t i = 1; i <= n; ++i){
            if (i % 5 == 0 & i % 3 == 0){
                res.push_back("FizzBuzz");
            }
            else if (i % 5 == 0){
                res.push_back("Buzz");
            }
            else if (i % 3 == 0){
                res.push_back("Fizz");
            }
            else {
                res.push_back(std::to_string(i));
            }
        }
        return res;

    }
};
// @lc code=end

