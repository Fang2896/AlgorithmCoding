/****************************************************************
 * @file name    : File name
 * @Description  : 
 * @Version      : 0.0
 * @Author       : M1kanN
 * @Date         : 2022-12-08 13:17:44
 * @LastEditTime : 2022-12-09 17:56:18
 ****************************************************************/
/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
class Solution {
public:
    class MyComparison {
    public:
        // 设计最大堆
        bool operator() (const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.second > rhs.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        /*
        * 1. 统计元素出现的频率
        * 2. 对频率排序
        * 3. 找出前k个高频元素
        */
        // 1.
        unordered_map<int, int> map;
        for(int num : nums)
            map[num]++;
        // 2.
        priority_queue<pair<int, int>, vector<pair<int, int>>, MyComparison> pri_que;
        // priority_queue<pair<int, int>> pri_que;
        for(auto it = map.begin(); it != map.end(); it++) {
            pri_que.push(*it);  // 注意，unordered_map的迭代器指向的是pair类型
            if(pri_que.size() > k) 
                pri_que.pop();  // 保持堆中只有k个元素
        }
        // 3.
        vector<int> result(k);
        for(int i = k - 1; i >= 0; i--) {
            result[i] = pri_que.top().first;
            pri_que.pop();
        }
        return result;
    }
};
// @lc code=end

