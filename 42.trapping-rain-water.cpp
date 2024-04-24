/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
int right_max_idx(std::vector<int>& height, int curr_idx){
    int res = curr_idx;
    int max = height[curr_idx];
    for (int i = curr_idx; i < height.size(); ++i ){
        if (height[i] > max){
            res = i;
            max = height[i];
        }
    }
    return res;
}

class Solution {
public:
    int trap(vector<int>& height) {

        if (height.size() < 3){
            return 0;
        }
        int res = 0;
        int c_left_max_idx = 0;
        int c_left_max = height[0];
        int c_right_max_idx = right_max_idx(height,1);
        int c_right_max = height[c_right_max_idx];

        for (int i = 1; i< height.size() -1 ; ++i){
            if (height[i] > c_left_max){
                c_left_max = height[i];
                c_left_max_idx = i;
            }
            if (i > c_right_max_idx){
                c_right_max_idx = right_max_idx(height,i+1);
                c_right_max = height[c_right_max_idx];
            }

            res += std::max(std::min(c_left_max, c_right_max) - height[i],0);

        }

        return res;
        
    }
};

// @lc code=end

