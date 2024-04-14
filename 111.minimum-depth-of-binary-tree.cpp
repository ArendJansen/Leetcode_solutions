/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
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
    int minDepth(TreeNode* root) {
        if (root == nullptr){
            return 0;
        }
        int depth =1;

        if (root -> left == nullptr){
            depth += minDepth(root -> right);
            return depth;
        }
        else if (root -> right == nullptr){
            depth += minDepth(root -> left);
            return depth; 
        }
        int ldepth = minDepth(root -> left);
        int rdepth = minDepth(root -> right);

        depth += (ldepth > rdepth) ? rdepth : ldepth;
        
        return depth;        
    }
};
// @lc code=end

