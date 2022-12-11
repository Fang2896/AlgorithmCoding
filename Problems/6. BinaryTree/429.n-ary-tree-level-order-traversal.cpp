/****************************************************************
 * @file name    : File name
 * @Description  : 
 * @Version      : 0.0
 * @Author       : M1kanN
 * @Date         : 2022-12-11 16:40:40
 * @LastEditTime : 2022-12-11 16:57:18
 ****************************************************************/
/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N-ary Tree Level Order Traversal
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
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> que;
        if(root != nullptr)
            que.push(root);
        vector<vector<int>> result;
        while(!que.empty()) { 
            int size = que.size();
            vector<int> vec;
            for(int i = 0; i < size; i++) {
                Node* node = que.front();
                que.pop();
                vec.push_back(node->val);
                // 遍历这个结点的孩子们
                for(int i = 0; i < node->children.size(); i++) {
                    if(node->children[i])
                        que.push(node->children[i]);
                }
            }
            result.push_back(vec);
        }
        return result;
    }
};
// @lc code=end

