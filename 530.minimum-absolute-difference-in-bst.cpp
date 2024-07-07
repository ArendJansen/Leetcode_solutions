/*
 * @lc app=leetcode id=530 lang=cpp
 *
 * [530] Minimum Absolute Difference in BST
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <algorithm>

class Solution {
public:
    TreeNode* prev = nullptr;
    void dfs(TreeNode * root, int & min){

        if (root == nullptr){
            return;
        }

        dfs(root -> left, min);

        if (prev){
            min = std::min(min, std::abs(root -> val - prev -> val));
        }
        prev = root;

        dfs(root -> right, min);
    }
    int getMinimumDifference(TreeNode* root) {
        int min = 100001;
        dfs(root, min);
        return min;
    }
};
// @lc code=end

