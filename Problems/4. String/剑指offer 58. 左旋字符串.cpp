/****************************************************************
 * @file name    : File name
 * @Description  : 
 * @Version      : 0.0
 * @Author       : M1kanN
 * @Date         : 2022-12-07 14:10:14
 * @LastEditTime : 2022-12-07 14:47:12
 ****************************************************************/
#include<iostream>
#include<vector>
#include<string>

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        // 翻转再翻转！
        reverse(s.begin(), s.begin() + n);
        reverse(s.begin() + n, s.end());
        reverse(s.begin(), s.end());
        return s;

    }
}