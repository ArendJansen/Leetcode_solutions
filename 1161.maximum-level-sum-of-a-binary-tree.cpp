/*
 * @lc app=leetcode id=1161 lang=cpp
 *
 * [1161] Maximum Level Sum of a Binary Tree
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
using namespace std;

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        std::queue<TreeNode *> lque;

        lque.push(root);

        int max = -INT_MAX;

        int clvl = 1;
        int mlvl = 1;


        while (!lque.empty()){
            int len = lque.size();
            int sum = 0;
            for (int i = 0;  i < len; ++i){
                sum += lque.front() -> val;

                if (lque.front() -> left != nullptr){
                    lque.push(lque.front() -> left);
                }
                if (lque.front() -> right != nullptr){
                    lque.push(lque.front() -> right);
                }
                lque.pop();
            }
            if (sum > max){
                mlvl = clvl;
                max = sum;
            }
            ++clvl;
            
        }

        return mlvl;

        
    }
};
// @lc code=end

