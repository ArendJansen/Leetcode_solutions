/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
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
#include <vector>
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {

        std::vector<int> results;
        if (root == nullptr) return results;
        
        std::vector<int> lval = inorderTraversal(root -> left);
        results.insert(results.end(), lval.begin(), lval.end());
        results.push_back(root -> val);
        
        std::vector<int> rval = inorderTraversal(root -> right);
        results.insert(results.end(), rval.begin(), rval.end());

        
        return results;  
    }
};
// @lc code=end

