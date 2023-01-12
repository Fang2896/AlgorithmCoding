/****************************************************************
 * @file name    : File name
 * @Description  : 
 * @Version      : 0.0
 * @Author       : M1kanN
 * @Date         : 2023-01-11 21:07:15
 * @LastEditTime : 2023-01-11 21:23:56
 ****************************************************************/
/*
 * @lc app=leetcode.cn id=559 lang=cpp
 *
 * [559] Maximum Depth of N-ary Tree
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int result;
    void getDepth(Node* node, int depth) {  // depth为当前node的深度
        result = depth > result ? depth : result;
        if((node->children).empty())   return; // 如果没有孩子直接返回
        for(auto curr : (node->children)) {   // 用curr来遍历每个孩子
            depth++;
            getDepth(curr, depth);
            depth--;
        }
        return;
    }
    int maxDepth(Node* root) {
        result = 0;
        if(root == nullptr) return result;
        getDepth(root, 1);
        return result;
    }
};
// @lc code=end

/* 递归遍历法
class Solution {
public:
    int result;
    void getDepth(Node* node, int depth) {  // depth为当前node的深度
        result = depth > result ? depth : result;
        if((node->children).empty())   return; // 如果没有孩子直接返回
        for(auto curr : (node->children)) {   // 用curr来遍历每个孩子
            depth++;
            getDepth(curr, depth);
            depth--;
        }
        return;
    }
    int maxDepth(Node* root) {
        result = 0;
        if(root == nullptr) return result;
        getDepth(root, 1);
        return result;
    }
};

*/