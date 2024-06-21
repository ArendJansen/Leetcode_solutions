/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
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

#include <queue>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr){
            return std::vector<int>();
        }
        std::vector<int> res;
        std::queue<TreeNode*> lque;
        lque.push(root);     

        while (!lque.empty()){
            int len = lque.size();

            for (int i = 0;  i < len; ++i){
                if (i == len - 1){
                    res.push_back(lque.front() -> val);
                }
                if (lque.front() -> left != nullptr){
                    lque.push(lque.front() -> left);
                }
                if (lque.front() -> right != nullptr){
                    lque.push(lque.front() -> right);
                }
                lque.pop();
            }
        }

        return res;


    }
};
// @lc code=end

