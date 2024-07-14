/*
 * @lc app=leetcode id=129 lang=cpp
 *
 * [129] Sum Root to Leaf Numbers
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
    void helper(TreeNode* root , int prev, int & sum){
        if (root == nullptr){
            return;
        }
        if (root -> left == nullptr && root -> right == nullptr){
            sum +=  (prev * 10 + root -> val);
        }

        helper(root -> left, prev * 10 + root -> val, sum);
        helper(root -> right, prev * 10 + root -> val, sum);


    }
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        helper(root,0,sum);
        return sum ;
    }
};
// @lc code=end

