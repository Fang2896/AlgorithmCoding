/*
 * @Author: M1kanN fangliu2896@gmail.com
 * @Date: 2022-12-06 14:36:55
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2022-12-06 16:26:22
 * @FilePath: \Algorithm\problems\4. String\541.reverse-string-ii.cpp
 * @Description: 541
 */
/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] Reverse String II
 */

// @lc code=start
class Solution {
public:
    string reverseStr(string s, int k) {
        for(int i = 0; i < s.size(); i += (2*k)) {
            // 每隔2k个字符，翻转这2k个字符中的前k个字符
            if(i + k <= s.size())
                reverse(s.begin() + i, s.begin() + i + k);
            else
                reverse(s.begin() + i, s.end());
        }
        return s;
    }
};
// @lc code=end

