/*
 * @lc app=leetcode id=832 lang=cpp
 *
 * [832] Flipping an Image
 */

// @lc code=start
using namespace std;
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        
        for (int i = 0;  i < image.size(); ++i){
            int k = 0;
            int j = image.size() -1 ;
            while (k < j){
                std::swap(image[i][k],image[i][j]);
                --j;
                ++k;
            }
        }

        for (int i = 0;  i < image.size(); ++i){
            for (int j = 0;  j < image.size(); ++j){
                image[i][j] ^= 1;
            }
        }

        return image;
    }
};
// @lc code=end

