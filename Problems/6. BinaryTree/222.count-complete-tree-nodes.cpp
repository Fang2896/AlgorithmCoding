/****************************************************************
 * @file name    : File name
 * @Description  : 
 * @Version      : 0.0
 * @Author       : M1kanN
 * @Date         : 2022-12-12 22:35:58
 * @LastEditTime : 2022-12-12 23:51:19
 ****************************************************************/
/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] Count Complete Tree Nodes
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
    int countNodes(TreeNode* root) {
        if(root == nullptr)   
            return 0;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        int leftDepth = 0, rightDepth = 0;
        while(left) {
            left = left->left;
            leftDepth++;
        }
        while(right) {
            right = right->right;
            rightDepth++;
        }
        if(leftDepth == rightDepth)
            return (2 << leftDepth) - 1;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};
// @lc code=end

/* 常规方法
class Solution {
public:
    int getNodeSum(TreeNode* cur) {
        if(cur == nullptr)
            return 0;
        int leftSum = getNodeSum(cur->left);
        int rightSum = getNodeSum(cur->right);
        return leftSum + rightSum + 1;
    }
    int countNodes(TreeNode* root) {
        return getNodeSum(root);
    }
};

*/