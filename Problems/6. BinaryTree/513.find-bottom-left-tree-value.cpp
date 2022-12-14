/****************************************************************
 * @file name    : File name
 * @Description  : 
 * @Version      : 0.0
 * @Author       : M1kanN
 * @Date         : 2022-12-14 16:33:29
 * @LastEditTime : 2022-12-14 16:59:35
 ****************************************************************/
/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] Find Bottom Left Tree Value
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
    // 层序遍历最简单
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> que;
        if(root != nullptr)
            que.push(root);
        int result = 0;
        while(!que.empty()) {
            int size = que.size();
            for(int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                if(i == 0) 
                    result = node->val;
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
        }
        return result;
    }
};
// @lc code=end

/* 递归回溯
class Solution {
public:
    int maxDepth = INT_MIN;
    int result;
    void traversal(TreeNode* root, int depth) {
        // 叶子节点
        if(root->left == nullptr && root->right == nullptr) {
            if(depth > maxDepth) {  // 进入一次就不进了
                maxDepth = depth;   // 保证是最底层的最左节点
                result = root->val;
            }
            return;
        }
        if(root->left) {
            traversal(root->left, depth + 1);
        }
        if(root->right) {
            traversal(root->right, depth + 1);
        }
        return;
    }
    int findBottomLeftValue(TreeNode* root) {
        traversal(root, 0);
        return result;
    }
};

*/