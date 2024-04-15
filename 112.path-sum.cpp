/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
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
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr){
            return false;
        }
        bool ltrue = false;
        bool rtrue = false;
        int val = root -> val;

        if (val == targetSum && root -> left == nullptr && root -> right == nullptr){
            return true;
        }

        if (root -> left != nullptr){
            ltrue = hasPathSum(root -> left, targetSum - val);
        }
        if (root -> right != nullptr){
            rtrue = hasPathSum(root -> right, targetSum - val);
        }

        if (ltrue || rtrue){
            return true;
        }
        return false;



    }
};
// @lc code=end

