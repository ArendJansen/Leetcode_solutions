/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> fin_res;
        if (root == nullptr){
            return fin_res;
        }
        std::queue<TreeNode*> que;
        que.push(root);

        while(!que.empty()){
            int qsize = que.size();
            std::vector<int> curval;
            for (int i = 0; i < qsize; ++i){
                root = que.front();
                que.pop();

                curval.push_back(root -> val);

                if (root -> left != nullptr){
                    que.push(root -> left);
                }
                if (root -> right != nullptr){
                    que.push(root -> right);
                }   
            }
            fin_res.push_back(curval);
        }
        return fin_res;     
    }
};
// @lc code=end

