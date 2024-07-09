/*
 * @lc app=leetcode id=222 lang=cpp
 *
 * [222] Count Complete Tree Nodes
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
    void helper(TreeNode* root, int & curr){
        if (root == nullptr){
            return;
        }
        ++curr;
        helper(root -> left, curr);
        helper(root -> right, curr);
    }
    int countNodes(TreeNode* root) {
        int curr  =0;
        helper(root, curr);
        return curr;
    }
};
// @lc code=end

