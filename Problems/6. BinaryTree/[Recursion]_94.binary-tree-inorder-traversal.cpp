/****************************************************************
 * @file name    : File name
 * @Description  : 
 * @Version      : 0.0
 * @Author       : M1kanN
 * @Date         : 2022-12-10 22:41:52
 * @LastEditTime : 2022-12-10 22:44:49
 ****************************************************************/
/*
 * @lc app=leetcode.cn id=94 lang=cpp
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
class Solution {
public:
    void traversal(TreeNode* cur, vector<int>& vec) {
        if(cur == nullptr)
            return;
        traversal(cur->left, vec);
        vec.push_back(cur->val);
        traversal(cur->right, vec);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        traversal(root ,result);
        return result;
    }
};
// @lc code=end

