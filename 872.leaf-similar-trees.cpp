/*
 * @lc app=leetcode id=872 lang=cpp
 *
 * [872] Leaf-Similar Trees
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
using namespace std;

class Solution {
public:
    void getLeafSequence(TreeNode* root, std::vector<int> & seq){

        if (root == nullptr){
            return;
        }
        if (root -> left == nullptr && root -> right == nullptr){
            seq.push_back(root -> val);
            return;
        }
        getLeafSequence(root -> left, seq);
        getLeafSequence(root -> right, seq);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        std::vector<int> seq1, seq2;
        getLeafSequence(root1, seq1);
        getLeafSequence(root2, seq2);

        if (seq1.size() != seq2.size()){
            return false;
        }

        for (int i = 0;  i < seq1.size(); ++i){
            if (seq1[i] != seq2[i]){
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

