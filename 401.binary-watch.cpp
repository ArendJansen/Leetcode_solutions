/*
 * @lc app=leetcode id=401 lang=cpp
 *
 * [401] Binary Watch
 */

// @lc code=start

std::vector<int> get_combs(int set_bits, int max_loop){
    std::vector<int> res;
    for (int i = 0; i < max_loop; ++i){
        if (__builtin_popcount(i) == set_bits){
            res.push_back(i);
        }
    }
    return res;
}

std::string paddedString(int number) {
    std::string str = std::to_string(number);

    if (str.length() < 2) {
        str = "0" + str;
    }
    return str;
}

std::vector<std::string> buildCombs(const std::vector<int>& vec1,
                                    const std::vector<int>& vec2){
    
    std::vector<std::string> res;
    for (int i = 0; i < vec1.size(); i++) {
        for (int j = 0; j < vec2.size(); j++) {
            std::string combination = 
                std::to_string(vec1[i]) + 
                ":" + 
                paddedString(vec2[j]);
            res.push_back(combination);     
        }                            
    }
    return  res;
}
class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        std::vector<std::string> res;

        for (int m = 0; m <= 5; ++m){
            for (int h = 0; h <= 3; ++h){
                if (h + m == turnedOn){
                    std::vector<int> hcombs = get_combs(h,12);
                    std::vector<int> mcombs = get_combs(m,60);

                    std::vector<std::string> tmp_res = buildCombs(hcombs, mcombs);
                    res.insert(res.end(), tmp_res.begin(), tmp_res.end());
                }
            }
        }
        return res;
    }
};
// @lc code=end

