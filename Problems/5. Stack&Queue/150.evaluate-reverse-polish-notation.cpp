/****************************************************************
 * @file name    : File name
 * @Description  : 
 * @Version      : 0.0
 * @Author       : M1kanN
 * @Date         : 2022-12-08 13:16:45
 * @LastEditTime : 2022-12-08 17:04:52
 ****************************************************************/
/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */

// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> st;
        for(string s : tokens) {
            if(s == "+" || s == "-" || s == "*" || s == "/") {
                long long num1 = st.top();
                st.pop();
                long long num2 = st.top();
                st.pop();
                if(s == "+")    st.push(num2 + num1);
                if(s == "-")    st.push(num2 - num1);
                if(s == "*")    st.push(num2 * num1);
                if(s == "/")    st.push(num2 / num1);
            } else 
                st.push(stoll(s));
        }
        int result = st.top();
        st.pop();
        return result;
    }
};
// @lc code=end

