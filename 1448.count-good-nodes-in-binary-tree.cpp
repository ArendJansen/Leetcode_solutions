/*
 * @lc app=leetcode id=1448 lang=cpp
 *
 * [1448] Count Good Nodes in Binary Tree
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
    int helper(TreeNode* root, int max_val){

        if (root == nullptr){
            return 0;
        }

        int max = root -> val > max_val ? root -> val : max_val;
        int count = max > root -> val ? 0 : 1;

        return count + helper(root -> left, max) + helper(root -> right, max);


    }
    int goodNodes(TreeNode* root) {
        
        return helper(root, -50000);
    }
};
// @lc code=end

