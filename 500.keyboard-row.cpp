/*
 * @lc app=leetcode id=500 lang=cpp
 *
 * [500] Keyboard Row
 */

// @lc code=start
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
    
        std::vector<std::string> res;
        std::unordered_map<char,int> keys;
        bool set;
        short val = 0;

        keys['q'] = 1;
        keys['w'] = 1;
        keys['e'] = 1;
        keys['r'] = 1;
        keys['t'] = 1;
        keys['y'] = 1;
        keys['u'] = 1;
        keys['i'] = 1;
        keys['o'] = 1;
        keys['p'] = 1;
        keys['Q'] = 1;
        keys['W'] = 1;
        keys['E'] = 1;
        keys['R'] = 1;
        keys['T'] = 1;
        keys['Y'] = 1;
        keys['U'] = 1;
        keys['I'] = 1;
        keys['O'] = 1;
        keys['P'] = 1;

        keys['a'] = 2;
        keys['s'] = 2;
        keys['d'] = 2;
        keys['f'] = 2;
        keys['g'] = 2;
        keys['h'] = 2;
        keys['j'] = 2;
        keys['k'] = 2;
        keys['l'] = 2;
        keys['A'] = 2;
        keys['S'] = 2;
        keys['D'] = 2;
        keys['F'] = 2;
        keys['G'] = 2;
        keys['H'] = 2;
        keys['J'] = 2;
        keys['K'] = 2;
        keys['L'] = 2;

        keys['z'] = 3;
        keys['x'] = 3;
        keys['c'] = 3;
        keys['v'] = 3;
        keys['b'] = 3;
        keys['n'] = 3;
        keys['m'] = 3;
        keys['Z'] = 3;
        keys['X'] = 3;
        keys['C'] = 3;
        keys['V'] = 3;
        keys['B'] = 3;
        keys['N'] = 3;
        keys['M'] = 3;

        for (auto word : words){
                set = true;
                val = keys[word[0]];
                for (int i = 1; i < word.length(); ++i){
                    if (keys[word[i]] != val){
                        set = false;
                        break;
                    }
                }
                if (set){
                    res.push_back(word);
                }
        }
        return res;
    }
};
// @lc code=end

