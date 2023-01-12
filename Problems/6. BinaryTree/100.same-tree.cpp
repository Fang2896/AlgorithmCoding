/****************************************************************
 * @file name    : File name
 * @Description  : 
 * @Version      : 0.0
 * @Author       : M1kanN
 * @Date         : 2023-01-11 19:41:36
 * @LastEditTime : 2023-01-11 19:55:51
 ****************************************************************/
/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] Same Tree
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr)    return true;
        queue<TreeNode*> que;
        que.push(p);    que.push(q);
        while(!que.empty()) {
            TreeNode* node1 = que.front();  que.pop();
            TreeNode* node2 = que.front(); que.pop();
            if(node1 == nullptr && node2 == nullptr) {
                continue;
            }
            else if((node1 == nullptr && node2 != nullptr) ||
                (node1 != nullptr && node2 == nullptr)) {
                return false;
            } else if(node1 != nullptr && node2 != nullptr) {
                if(node1->val != node2->val) {
                    return false;
                }
            }
            que.push(node1->left);
            que.push(node2->left);
            que.push(node1->right);
            que.push(node2->right);
        }
        return true;
    }
};
// @lc code=end

