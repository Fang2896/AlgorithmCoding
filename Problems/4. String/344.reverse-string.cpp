/*
 * @Author: M1kanN fangliu2896@gmail.com
 * @Date: 2022-12-06 14:36:45
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2022-12-06 16:41:07
 * @FilePath: \Algorithm\Problems\4. String\344.reverse-string.cpp
 * @Description: No.344
 */
/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] Reverse String
 */

// @lc code=start
class Solution {
public:
    void reverseString(vector<char>& s) {
        // 双指针？
        for(int left = 0, right = s.size() - 1; left < s.size() / 2; left++, right--) 
            swap(s[left], s[right]);
    }
    
};
// @lc code=end

