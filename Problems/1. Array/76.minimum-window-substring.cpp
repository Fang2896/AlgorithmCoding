/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */

/*
思路分析：
    滑动窗口 + 哈希表unordered_map
    right一直向右滑，直到满足条件，然后记录当前string
    接着left右滑，直到不满足条件。
*/

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        // correct用来匹配滑动窗口内符合的
        int left = 0, correct = 0;
        string res = s + "auxiliary";
        unordered_map<char, int> sMap, tMap;
        // 建立t字符串的字典
        for(auto &i : t) 
            ++tMap[i];
        for(int right = 0; right < s.size(); ++right) {
            ++sMap[s[right]];
            if(sMap[s[right]] <= tMap[s[right]])
                ++correct;
            while(left < right && sMap[s[left]] > tMap[s[left]])
                --sMap[s[left++]];
            // 窗口一旦满足，就记录下来
            if(correct == t.size()) {
                // 更新最短的子串
                if(right - left + 1 < res.size())
                    res = s.substr(left, right - left + 1);
            }
        }
        return res == s + "auxiliary" ? "" : res;
    }
};
// @lc code=end

