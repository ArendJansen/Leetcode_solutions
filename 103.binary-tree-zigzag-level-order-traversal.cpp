/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
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
#include <queue>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> res;

        if (root == nullptr){
            return res;
        }
        queue<TreeNode *> lq;

        bool left = true;

        lq.push(root);

        while(!lq.empty()){
            int size = lq.size();
            vector<int> curr;

            for (int i = 0; i < size; ++i){
                TreeNode* tmp = lq.front();
                lq.pop();
                if (tmp -> left != nullptr){
                    lq.push(tmp -> left);
                }
                if (tmp -> right != nullptr){
                    lq.push(tmp -> right);
                }
                curr.push_back(tmp -> val);
            }
            if (left){
                res.push_back(curr);
                left = false;
            }
            else{
                std::reverse(curr.begin(), curr.end());
                res.push_back(curr);
                left = true;
            }
        }

        return res;

        
    }
};
// @lc code=end

