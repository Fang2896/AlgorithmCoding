/****************************************************************
 * @file name    : File name
 * @Description  : 
 * @Version      : 0.0
 * @Author       : M1kanN
 * @Date         : 2022-12-08 13:15:31
 * @LastEditTime : 2022-12-08 15:50:39
 ****************************************************************/
/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

// @lc code=start
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        int len = s.size();
        for(char c : s) {
            if(st.empty() || c != st.top())
                st.push(c);
            else 
                st.pop();
        }
        string result = "";
        while(!st.empty()) {
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
// @lc code=end

