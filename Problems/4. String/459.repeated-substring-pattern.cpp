// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem459.h"

using namespace std;
// @before-stub-for-debug-end

/****************************************************************
 * @file name    : File name
 * @Description  : 
 * @Version      : 0.0
 * @Author       : M1kanN
 * @Date         : 2022-12-06 14:52:20
 * @LastEditTime : 2022-12-07 19:43:15
 ****************************************************************/
/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] Repeated Substring Pattern
 */

// @lc code=start
class Solution {
public:
    /****************************************************************
     * @Funticon name: getNext
     * @Berif: Get the next array of string
     * @Author: M1kanN
     * @Data: Do not 54
     * @Note: Need note condition
     * @param {int*} next
     * @param {string&} s
     ****************************************************************/
    void getNext2(int* next, const string& s)  
    {  
        next[0] = -1;  
        int k = -1;  
        int j = 0;  
        while (j < s.size() - 1) {  
            //p[k]表示前缀，p[j]表示后缀  
            if (k == -1 || s[j] == s[k])   
            {  
                ++k;  
                ++j;  
                next[j] = k;  
            }  else   
                k = next[k];
        }  
    }  
    bool repeatedSubstringPattern(string s) {
        if(s.size() == 0)
            return false;
        int next[s.size()];
        getNext2(next, s);
        int len = s.size();
        if(next[len - 1] != -1 && len % (len - (next[len - 1] + 1)) == 0)
            return true;
        return false;
    }
};
// @lc code=end

