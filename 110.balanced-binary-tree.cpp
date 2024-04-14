/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
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

int maxDepth(TreeNode* root) {

    if (root == nullptr){
        return 0;
    }
    int depth =1;


    int ldepth = maxDepth(root -> left);
    int rdepth = maxDepth(root -> right);

    depth += (ldepth > rdepth) ? ldepth : rdepth;
    
    return depth;
}
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr){
            return true;
        }
        int ldepth = maxDepth(root -> left);
        int rdepth = maxDepth(root -> right);

        if (abs(ldepth - rdepth) > 1){
            return false;
        }
        else {
            bool ltrue = isBalanced(root -> left);
            bool rtrue = isBalanced(root -> right);

            if(!ltrue || !rtrue){
                return false;
            }
        }
        return true;



        
    }
};
// @lc code=end

