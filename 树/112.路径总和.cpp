/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root){
            if(root->val == sum && root->left==NULL && root->right == NULL)
                return true;
            bool a = hasPathSum(root->left,sum-root->val);
            bool b = hasPathSum(root->right,sum-root->val);
            return a||b;
        }
        return false;
    }
};
// @lc code=end

