/****************************************************************
 * @file name    : File name
 * @Description  : KMP
 * @Version      : 0.0
 * @Author       : M1kanN
 * @Date         : 2022-12-06 14:52:08
 * @LastEditTime : 2022-12-07 15:33:29
 ****************************************************************/
/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] Find the Index of the First Occurrence in a String
 */

// @lc code=start
class Solution {
public:
    void getNext(int* next, const string& s) {
        int j = -1;
        next[0] = j;
        for(int i = 1; i < s.size(); i++) {
            while(j >= 0 && s[i] != s[j + 1])
                j = next[j];
            if(s[i] == s[j + 1])
                j++;
            next[i] = j;
        }
    }
    int strStr(string haystack, string needle) {
        // KMP算法
        
    }
};
// @lc code=end

