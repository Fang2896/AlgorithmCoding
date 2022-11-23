/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // 滑动窗口优化！
        // 不再统计滑动窗口和字符串p中每种字母的数量，而是统计
        // 滑动窗口和字符串p中每种字母数量的差，并引入变量differ来记录
        // 当前窗口与字符串p中数量不同的字母的个数，
        // 并在滑动窗口的过程中维护它
        // 在判断滑动窗口中每种字母的数量与字符串p中每种字母的数量是否相同时
        // 只需要判断differ是否为0即可
        int sLen = s.size(), pLen = p.size();
        if(sLen < pLen)
            return vector<int>();
        vector<int> ans;
        vector<int> count(26);
        for(int i = 0; i < pLen; ++i) {
            ++count[s[i] - 'a'];
            --count[p[i] - 'a'];    // 优化关键！这里的count是各个字母的differ！
        }
        int differ = 0;
        // 用for循环第一次统计differ数量
        for(int j = 0; j < 26; ++j) {
            if(count[j] != 0)
                ++differ;
        }
        if(differ == 0)
            ans.emplace_back(0);
        // 上面的步骤是第一次的初始化，后面开始滑动窗口的移动！
        // 注意count中若为1，说明滑动窗口中对应的字母更多，若为-1，则更少
        for(int i = 0; i < sLen - pLen; ++i) {
            if(count[s[i] - 'a'] == 1)  // 窗口中字母 s[i] 的数量与字符串 p 中的数量从不同变得相同
                --differ;
            else if (count[s[i] - 'a'] == 0)  // 窗口中字母 s[i] 的数量与字符串 p 中的数量从相同变得不同  
                ++differ;
            --count[s[i] - 'a'];    // 滑动窗口左侧移动出去了，所以减去

            if(count[s[i + pLen] - 'a'] == -1)  // 需要进来的是刚好在滑动窗口缺少的那一个
                --differ;
            else if(count[s[i + pLen] - 'a'] == 0)
                ++differ;
            ++count[s[i + pLen] - 'a'];

            if(differ == 0) // 说明对应的窗口满足条件
                ans.emplace_back(i + 1);
        }
        return ans;
    }
};
// @lc code=end


/* 滑动窗口方法
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // 遇到匹配题一般解法是滑动窗口
        int sLen = s.size(), pLen = p.size();
        if(sLen < pLen) 
            return vector<int>();
        vector<int> ans;
        vector<int> sCount(26);
        vector<int> pCount(26);
        // 第一次滑动判断
        for(int i = 0; i < pLen; i++) {
            ++sCount[s[i] - 'a'];
            ++pCount[p[i] - 'a'];
        }
        if(sCount == pCount) 
            ans.emplace_back(0);
        
        for(int i = 0; i < sLen - pLen; ++i) {
            --sCount[s[i] - 'a'];   // 离开窗口的一个字符
            ++sCount[s[i + pLen] - 'a'];    // 进入窗口的一个字符
            if(sCount == pCount)
                ans.emplace_back(i+1);
        }
        return ans;
    }
};
*/
