/****************************************************************
 * @file name    : File name
 * @Description  : KMP
 * @Version      : 0.0
 * @Author       : M1kanN
 * @Date         : 2022-12-06 14:52:08
 * @LastEditTime : 2022-12-07 19:27:53
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
        next[0] = -1;
        int j = -1;
        for(int i = 1;i < s.size(); i++){
            while(j >= 0 && s[i] != s[j + 1]) {
                j = next[j];
            }
            if(s[i] == s[j + 1]) {
                j++;
            }
            next[i] = j;
        }
    }
    
    int strStr(string haystack, string needle) {
        // KMP算法
        int i = 0, j = 0;
        int N = haystack.size(), M = needle.size();
        int next[M];
        getNext(next, needle);
        while(i < N && j < M) {
            if(j == -1 || haystack[i] == needle[j]) {
                i++;
                j++;
            } else {
                j = next[j];    // 模式串移动
            }
        }
        if(j == M)
            return i - j;
        else
            return -1;
    }
};
// @lc code=end

