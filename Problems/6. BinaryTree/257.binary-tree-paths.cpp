/****************************************************************
 * @file name    : File name
 * @Description  : 
 * @Version      : 0.0
 * @Author       : M1kanN
 * @Date         : 2022-12-14 15:28:57
 * @LastEditTime : 2022-12-14 16:17:02
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
        stack<TreeNode*> treeSt;
        stack<string> pathSt;
        vector<string> result;
        if(root == nullptr)
            return result;
        treeSt.push(root);
        pathSt.push(to_string(root->val));
        while(!treeSt.empty()) {
            TreeNode* node = treeSt.top();
            treeSt.pop();
            string path = pathSt.top();
            pathSt.pop();
            if(node->left == nullptr && node->right == nullptr) // 叶子
                result.push_back(path);
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

/* 回溯版本 
class Solution {
private:
    // 回溯
    void traversal(TreeNode* cur, vector<int>& path, vector<string>& result) {
        path.push_back(cur->val);   // 中，写在这里的原因是，最后一个节点也得加入path
        // 叶子节点为终止条件, 遇到则记录
        if(cur->left == nullptr && cur->right == nullptr) { // 遇到叶子节点
            string sPath;
            for(int i = 0; i < path.size() - 1; i++) {
                sPath += to_string(path[i]);
                sPath += "->";
            }
            sPath += to_string(path[path.size() - 1]);  // 记录最后一个节点
            result.push_back(sPath);
            return;
        }
        if(cur->left) {
            traversal(cur->left, path, result);
            path.pop_back();    // 回溯
        }
        if(cur->right) {
            traversal(cur->right, path, result);
            path.pop_back();    // 回溯
        }

    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        vector<int> path;
        if(root == nullptr) return result;
        traversal(root, path, result);
        return result;
    }
};


*/