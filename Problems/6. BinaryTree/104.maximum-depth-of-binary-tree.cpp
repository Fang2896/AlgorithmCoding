/****************************************************************
 * @file name    : File name
 * @Description  : 
 * @Version      : 0.0
 * @Author       : M1kanN
 * @Date         : 2023-01-11 20:29:30
 * @LastEditTime : 2023-01-12 20:36:15
 ****************************************************************/
/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
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
    int result;
    void getDepth(TreeNode* node, int depth) {
        result = result < depth ? depth : result;
        if(!node->left && !node->right) return;
        if(node->left) {
            depth++;
            getDepth(node->left, depth);
            depth--;
        }
        if(node->right) {
            depth++;
            getDepth(node->right, depth);
            depth--;
        }
        return;
    }
    int maxDepth(TreeNode* root) {
        // 前序遍历
        result = 0;
        if(root == nullptr) return result;
        getDepth(root ,1);
        return result;
    }
};
// @lc code=end

/*
class Solution {
public:
// 递归遍历
// Your runtime beats 31.39 % of cpp submissions
// Your memory usage beats 55.25 % of cpp submissions (18.4 MB)
    int maxDepth(TreeNode* root) {
        // 递归法
        if(root == nullptr) return 0;
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        int depth = max(leftDepth, rightDepth) + 1;
        return depth;
    }
};
*/



/*
// 用层次遍历：挺低效的
// Your runtime beats 6.19 % of cpp submissions
// Your memory usage beats 30.62 % of cpp submissions (18.4 MB)

class Solution {
public:
    int maxDepth(TreeNode* root) {
        int result = 0;
        if(root == nullptr) return result; 
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()) {
            result++;
            int size = que.size();
            for(int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
        }
        return result;
    }
};
*/