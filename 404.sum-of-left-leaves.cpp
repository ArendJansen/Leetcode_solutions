/*
 * @lc app=leetcode id=404 lang=cpp
 *
 * [404] Sum of Left Leaves
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

int helperLeftLeaves(TreeNode* root, bool is_left) {
        
        if (root == nullptr){
            return 0;
        }

        if (root -> left  == nullptr &&
            root -> right == nullptr &&
            is_left){
            return root -> val;
        }
        else {
        return helperLeftLeaves(root -> left, true) + helperLeftLeaves(root -> right, false);

        }
}
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        
        if (root == nullptr){
            return 0;
        }
        
        return helperLeftLeaves(root -> left, true) + helperLeftLeaves(root -> right, false);
    }
};
// @lc code=end

