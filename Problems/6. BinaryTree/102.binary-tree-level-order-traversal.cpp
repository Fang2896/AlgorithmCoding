/****************************************************************
 * @file name    : File name
 * @Description  : 
 * @Version      : 0.0
 * @Author       : M1kanN
 * @Date         : 2022-12-11 15:30:02
 * @LastEditTime : 2022-12-11 15:46:46
 ****************************************************************/
/*
 * @lc app=leetcode.cn id=102 lang=cpp
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

// 递归法
class Solution {
public:
    void order(TreeNode* cur, vector<vector<int>>& result, int depth) {
        if(cur == nullptr)
            return;
        if(result.size() == depth)
            result.push_back(vector<int>());
        result[depth].push_back(cur->val);
        order(cur->left, result, depth + 1);
        order(cur->right, result, depth + 1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        int depth = 0;
        order(root, result, depth);
        return result;
    }
};
// @lc code=end

/* 迭代法
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        // 层序一眼队列
        vector<vector<int>> result;
        queue<TreeNode*> que;
        if(root != nullptr)
            que.push(root);
        while(!que.empty()) {
            int size = que.size();  // 记录目前的队列长度
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
        return result;
    }
};


*/