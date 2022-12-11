/****************************************************************
 * @file name    : File name
 * @Description  :
 * @Version      : 0.0
 * @Author       : M1kanN
 * @Date         : 2022-12-11 15:51:02
 * @LastEditTime : 2022-12-11 16:12:23
 ****************************************************************/
/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] Binary Tree Level Order Traversal II
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
    void order(TreeNode* cur, vector<vector<int>>& result, int depth) {
        if(cur == nullptr)
            return;
        if(depth == result.size())
            result.push_back(vector<int>());
        result[depth].push_back(cur->val);
        order(cur->left, result, depth + 1);
        order(cur->right, result, depth + 1);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        order(root, result, 0);
        reverse(result.begin(), result.end());
        return result;
    }
};
// @lc code=end

/* 迭代version
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        // 层序遍历之后翻转数组
        vector<vector<int>> result;
        queue<TreeNode*> que;
        if(root != nullptr)
            que.push(root);
        while(!que.empty()) {
            int size = que.size();
            vector<int> vec;
            for(int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                vec.push_back(node->val);
                if(node->left)
                    que.push(node->left);
                if(node->right)
                    que.push(node->right);
            }
            result.push_back(vec);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
*/