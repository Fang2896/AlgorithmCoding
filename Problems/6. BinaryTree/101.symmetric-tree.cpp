/****************************************************************
 * @file name    : File name
 * @Description  : 
 * @Version      : 0.0
 * @Author       : M1kanN
 * @Date         : 2022-12-11 22:48:59
 * @LastEditTime : 2022-12-12 00:19:52
 ****************************************************************/
/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] Symmetric Tree
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
    // 注意！这并不适用于层序遍历！只是照着每层，不同的顺序放入容器！
    bool isSymmetric(TreeNode* root) {
        // 用queue！
        if(root == nullptr) return true;
        queue<TreeNode*> que;
        que.push(root->left);
        que.push(root->right);
        while(!que.empty()) {
            TreeNode* leftNode = que.front();
            que.pop();
            TreeNode* rightNode = que.front();
            que.pop();
            if(!leftNode && !rightNode) // 左右均为空则对称
                continue;
            // 若有不为空？
            if((!leftNode || !rightNode || (leftNode->val != rightNode->val)))
                return false;
            // 注意加入的顺序！
            que.push(leftNode->left);
            que.push(rightNode->right);
            que.push(leftNode->right);
            que.push(rightNode->left);
        }
        return true;
    }
};
// @lc code=end

/*
class Solution {
public:
    // 用比较函数来比较，两个子树，是否互为镜像对称
    bool compare(TreeNode* left, TreeNode* right) {
        if(left == nullptr && right != nullptr) 
            return false;
        else if(left != nullptr && right == nullptr) 
            return false;
        else if(left == nullptr && right == nullptr)
            return true;
        else if(left->val != right->val)
            return false;
        bool outside = compare(left->left, right->right);
        bool inside = compare(left->right, right->left);
        bool isSame = outside && inside;
        return isSame;
    }
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;
        return compare(root->left, root->right);
    }
};
*/