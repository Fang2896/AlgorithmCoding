/*
 * @lc app=leetcode.cn id=844 lang=cpp
 *
 * [844] Backspace String Compare
 */

// @lc code=start
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        // 基本思路，逆序扫描，因为遇到#就退格，所以逆序是很重要的
        int skipS = 0, skipT = 0;
        int i = s.length() - 1, j = t.length() - 1;
        while(i>=0 || j>=0) { // 确定下一个没有被消除的s中的字符
            while(i>=0) {
                if(s[i] == '#'){
                    skipS++, i--;
                } else if (skipS > 0)
                    skipS--, i--;
                else
                    break;
            }
            while(j>=0) {   // 确定下一个没有被消除的t中的字符
                if(t[j] == '#') {
                    skipT++, j--;
                } else if (skipT > 0)
                    skipT--, j--;
                else
                    break;
            }
            if(i>=0 && j>=0) {
                if(s[i] != t[j])
                    return false;
            } else {
                if(i >=0 || j >= 0)     // 只有一个大于0,不能继续比较了
                    return false;
            }
            i--, j--;   // 比较完了，下一个！
        }
        return true;    // 所有比较完成，说明正确！
    }
};
// @lc code=end

