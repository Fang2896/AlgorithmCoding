/****************************************************************
 * @file name    : File name
 * @Description  : 
 * @Version      : 0.0
 * @Author       : M1kanN
 * @Date         : 2022-12-08 13:15:09
 * @LastEditTime : 2022-12-08 15:06:18
 ****************************************************************/
/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        int len = s.size();
        if(len % 2 != 0) 
            return false;
        stack<char> st;
        for(int i = 0; i < len; i++) {
            if (s[i] == '(')
                st.push(')');
            else if (s[i] == '{')
                st.push('}');
            else if (s[i] == '[')
                st.push(']');
            else if (st.empty() || st.top() != s[i])
                return false;
            else 
                st.pop();
        }
        return st.empty();
    }
};
// @lc code=end

