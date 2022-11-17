/*
 * @lc app=leetcode.cn id=904 lang=cpp
 *
 * [904] Fruit Into Baskets
 */

/*
读题    fruits[]数组，存着第i棵树的果实的种类
规则    只有2个篮子，一个篮子只能装一种果实。无数量限制
            可以从任意树开始，但一颗树只能摘一个果实，只能向右走
            摘的果实必须可以放进一个篮子
            当遇到一种不能放进两个篮子的树，停止！
即：    给定fruits，返回能摘果实的最大数量
抽象化：
        给定一个数组，求出这个数组中，最大的子串长度
        该子串仅包含2种类型！
解题思路尝试：
        用双指针 / 移动窗口法
        移动窗口的限制条件是必须只有2种类型。
        每次移动都记录下来当前的值并且当下一个移动不符合的时候，更新最大值！
难点及其解决思路
        1. 如何确定滑动窗口内仅有2种？
            用哈希表，存储窗口内的数以及出现的次数
            当然也可以直接比较俩次就行了，反正只有俩个篮子
        2. 滑动窗口的移动策略？
            right一直移动，当不满足要求的时候，则不断移动left
            直到满足要求，即直到fruits[left]出现的次数等于0，
            然后将其从哈希表移除！
*/

// @lc code=start
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int, int> cnt;
        int ans = 0, left = 0;
        for(int right = 0; right < n; ++right) {
            ++cnt[fruits[right]];
            while(cnt.size() > 2) {
                auto it = cnt.find(fruits[left]);
                --it->second;
                if(it->second == 0) {
                    cnt.erase(it);
                }
                ++left;
            }
            ans = max (ans, right - left + 1);
        }
        return ans;
    }
};
// @lc code=end

