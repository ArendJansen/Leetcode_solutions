/*
 * @lc app=leetcode id=345 lang=cpp
 *
 * [345] Reverse Vowels of a String
 */

// @lc code=start

bool is_vowel(char x){
    if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u'  ||
        x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U'){
        return true;
    }
    return false;
}

class Solution {
public:
    string reverseVowels(string s) {

        int i = 0;
        int j = s.size() -1;

        while (i < j){
            if (is_vowel(s[i]) && is_vowel(s[j])){
                std::swap(s[i],s[j]);
                --j;
                ++i;
            }
            else if (is_vowel(s[i])){
                --j;
            }
            else if (is_vowel(s[j])){
                ++i;
            }
            else{
                --j;
                ++i;
            }
        }

        return s;
        
    }
};
// @lc code=end

