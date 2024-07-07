/*
 * @lc app=leetcode id=637 lang=cpp
 *
 * [637] Average of Levels in Binary Tree
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
using namespace std;


class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> lque;
        lque.push(root);

        int k =0;
        double avg = 0;
        vector<double> res;

        while (!lque.empty()){
            k = lque.size();
            avg = 0;
            for (int i = 0;  i < k; ++i){
                avg += lque.front() -> val;
                if (lque.front() -> left != nullptr){
                    lque.push(lque.front() -> left);
                }
                if (lque.front() -> right != nullptr){
                    lque.push(lque.front() -> right);
                }
                lque.pop();
            }
            avg /= k;
            res.push_back(avg);

        }
        return res;



    }
};
// @lc code=end

