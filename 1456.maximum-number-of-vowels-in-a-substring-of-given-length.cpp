/*
 * @lc app=leetcode id=1456 lang=cpp
 *
 * [1456] Maximum Number of Vowels in a Substring of Given Length
 */

// @lc code=start
#include <string>
using namespace std;
class Solution {
public:
    // int countVowels(std::string& s){
    //     int count = 0;
    //     for (char x : s){
    //         if (x == 'a'  || x == 'i' || x == 'o' || x == 'u' || x == 'e'){
    //             ++count;
    //         }
    //     }
    //     return count;
    // }
    bool isVowel(const char & x){
        return x == 'a'  || x == 'i' || x == 'o' || x == 'u' || x == 'e';
    }
    int maxVowels(string s, int k) {
        int count =0, max = 0;
        for (int i = 0;  i < k; ++i){
           if (isVowel(s[i])){++count;} 
        }
        max = count;
        int r = k;
        while(r < s.length()){
            if (isVowel(s[r-k])){
                --count;
            }
            if (isVowel(s[r])){
                ++count;
            }

            max = count > max ? count : max;
            ++r;
        }

        return max;
    }
};
// @lc code=end

