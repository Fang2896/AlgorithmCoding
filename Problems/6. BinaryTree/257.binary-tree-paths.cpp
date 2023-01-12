/****************************************************************
 * @file name    : File name
 * @Description  : 
 * @Version      : 0.0
 * @Author       : M1kanN
 * @Date         : 2023-01-12 21:01:11
 * @LastEditTime : 2023-01-12 22:06:13
 ****************************************************************/
/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] Binary Tree Paths
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
    vector<string> binaryTreePaths(TreeNode* root) {
        // 类似前序遍历！！一边遍历一边记录！
        stack<TreeNode*> treeSt;
        stack<string> pathSt;
        vector<string> result;
        if(root == nullptr) return result;
        treeSt.push(root);
        pathSt.push(to_string(root->val));
        while(!treeSt.empty()) {
            TreeNode* node = treeSt.top();
            treeSt.pop();
            string path = pathSt.top();
            pathSt.pop();
            if(!node->left && !node->right) {
                result.push_back(path);
            }
            if(node->right) {
                treeSt.push(node->right);
                pathSt.push(path + "->" + to_string(node->right->val));
            }
            if(node->left) {
                treeSt.push(node->left);
                pathSt.push(path + "->" + to_string(node->left->val));
            }
        }
        return result;
    }
};
// @lc code=end

/* 回溯法
class Solution {
public:
    void traversal(TreeNode* node, vector<int>& path, vector<string>& result) {
        path.push_back(node->val);
        if(!node->left && !node->right) {
            string sPath;
            for(auto ch : path) {
                sPath += to_string(ch);
                sPath += "->";
            }
            sPath.pop_back();   sPath.pop_back();
            result.push_back(sPath);
            return;
        }
        if(node->left) {
            traversal(node->left, path, result);
            path.pop_back();
        }
        if(node->right) {
            traversal(node->right, path, result);
            path.pop_back();
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        // 什么时候返回？ 到叶子结点的时候。什么时候回溯？要往上走的时候
        vector<string> result;
        vector<int> path;
        if(root == nullptr) return result;
        traversal(root, path, result);
        return result;
    }
};
*/