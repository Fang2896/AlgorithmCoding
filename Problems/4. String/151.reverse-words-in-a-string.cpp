/****************************************************************
 * @file name    : File name
 * @Description  : 
 * @Version      : 0.0
 * @Author       : M1kanN
 * @Date         : 2022-12-06 14:51:07
 * @LastEditTime : 2022-12-07 14:08:53
 ****************************************************************/
/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 */

// @lc code=start
class Solution {
public:
    // 参考27题来移除空格！
    // 
    void removeExtraSpaces(string& s) {
        int slow = 0;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] != ' ') {
                if(slow != 0)   // 第一个单词前不应该有空格
                    s[slow++] = ' ';
                while(i < s.size() && s[i] != ' ')
                    s[slow++] = s[i++];
            }
        }
        s.resize(slow);
    }
    void reverse(string& s, int start, int end) {
        for(int i = start, j = end; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
    }
    string reverseWords(string s) {
        // 移除多余空格
        // 整个字符串翻转
        // 每个单词翻转
        removeExtraSpaces(s);
        reverse(s, 0, s.size() - 1);
        int start = 0;
        for(int i = 0; i <= s.size(); ++i) {
            if(i == s.size() || s[i] == ' ') {  // i 到达了该翻转的地方
                reverse(s, start, i - 1);
                start = i + 1;  // 跳过空格即为下一个单词！
            }
        }
        return s;
    }
};
// @lc code=end


/* 用erase来移除空格的话，复杂度会变成n^2
void removeExtraSpaces(string& s) {
        for(int i = s.size() - 1; i > 0; i--) {
            if(s[i] == s[i-1] && s[i] == ' ')
                s.erase(s.begin() + i);
        }
        // 记得考虑字符串最后的空格
        if(s.size() > 0 && s[s.size() - 1] == ' ')
            s.erase(s.begin() + s.size() - 1);
        // 删除字符串最前面的空格
        if(s.size() > 0 && s[0] == ' ')
            s.erase(s.begin());
    }
*/

/* version2.0：双指针法移除空格！ 快慢指针
    void removeExtraSpaces(string& s) {
        int slowIndex = 0, fastIndex = 0;
        // 考虑前面的空格
        while(s.size() > 0 && fastIndex < s.size() && s[fastIndex] == ' ')
            fastIndex++;
        // 考虑中间部分
        // 用快指针掠过空格，用慢指针记录 
        for( ; fastIndex < s.size(); fastIndex++) {
            if(fastIndex - 1 > 0
                    && s[fastIndex - 1] == s[fastIndex]
                    && s[fastIndex] == ' ')
                continue;
            else 
                s[slowIndex++] = s[fastIndex];
        }
        // 考虑尾部(可能留一个空格！)
        if(slowIndex - 1 > 0 && s[slowIndex - 1] == ' ')
            s.resize(slowIndex - 1);
        else
            s.resize(slowIndex);
    }
*/