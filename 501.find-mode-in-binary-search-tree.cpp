/*
 * @lc app=leetcode id=501 lang=cpp
 *
 * [501] Find Mode in Binary Search Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 * 
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include <unordered_map>

void Helper(TreeNode* root, std::unordered_map<int,int>& lmap){

    if (root){
        ++lmap[root -> val];
        Helper(root -> left, lmap);
        Helper(root -> right, lmap);
    }
}
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        std::unordered_map<int,int> lmap;
        std::vector<int> res;
        int max_count = 0;
        Helper(root,lmap);

        for (const auto & pair : lmap){
            if (pair.second > max_count){
                max_count = pair.second;
            }
        }
        for (const auto & pair : lmap){
            if (pair.second == max_count){
                res.push_back(pair.first);
            }
        }

        return res;
        
    }
};
// @lc code=end

