/****************************************************************
 * @file name    : File name
 * @Description  : 
 * @Version      : 0.0
 * @Author       : M1kanN
 * @Date         : 2022-12-11 17:06:21
 * @LastEditTime : 2022-12-11 21:47:06
 ****************************************************************/
/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
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
    int minDepth(TreeNode* root) {
        if(root == nullptr)
            return 0;
        if(!root->left && !root->right)
            return 1;
        int minD = INT_MAX;
        if(root->left)
            minD = min(minDepth(root->left), minD);
        if(root->right)
            minD = min(minDepth(root->right), minD);
        
        return minD + 1;
    }
};
// @lc code=end

/*
class Solution {
public:
    int minDepth(TreeNode* root) {
        // 层序遍历？
        // 如何判断为最低点？ 左右孩子都为空！
        if(root == nullptr)
            return 0;
        int depth = 0;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()) {
            int size = que.size();
            depth++;
            for(int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
                if(!node->left && !node->right)
                    return depth;
            }
        }
        return depth;
    }
};


*/