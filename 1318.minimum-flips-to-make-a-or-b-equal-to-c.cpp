/*
 * @lc app=leetcode id=1318 lang=cpp
 *
 * [1318] Minimum Flips to Make a OR b Equal to c
 */

// @lc code=start
#include <bitset>
using namespace std;

class Solution {
public:
    int minFlips(int a, int b, int c) {


        std::bitset<32> bita(a);
        std::bitset<32> bitb(b);
        std::bitset<32> bitc(c);
        int count = 0; 

        for (int i = 0;  i < bitc.size(); ++i){
            if (bitc[i] == 1){
                if (bita[i] == 1 || bitb[i] == 1){
                    continue;
                }
                else {
                    ++count;
                }
            }
            else if (bitc[i] == 0){
                if (bita[i] == 1){
                    ++count;
                }
                if (bitb[i] == 1){
                    ++count;
                }
            }
        }

        return count;
        
    }
};
// @lc code=end

