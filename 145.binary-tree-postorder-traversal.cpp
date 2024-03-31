/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
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
    vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> results;
        if (root == nullptr) return results;
        
        std::vector<int> lval = postorderTraversal(root -> left);
        results.insert(results.end(), lval.begin(), lval.end());
        
        std::vector<int> rval = postorderTraversal(root -> right);
        results.insert(results.end(), rval.begin(), rval.end());

        results.push_back(root -> val);

        return results;  
    }
};
// @lc code=end

