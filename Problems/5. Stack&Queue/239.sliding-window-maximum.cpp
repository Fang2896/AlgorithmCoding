/****************************************************************
 * @file name    : File name
 * @Description  : 
 * @Version      : 0.0
 * @Author       : M1kanN
 * @Date         : 2022-12-08 13:17:07
 * @LastEditTime : 2022-12-08 17:48:19
 ****************************************************************/
/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */

// @lc code=start
class Solution {
private:
    // 实现单调队列
    class MyQueue {
    public:
        deque<int> que;
        // 每次弹出的时候，比较当前要弹出的数值是否等于队列出口元素的数值
        // 如果相等，则弹出
        // 同时pop之前必须判断队列当前是否为空
        void pop(int value) {
            if(!que.empty() && value == que.front())
                que.pop_front();
        }
        // 如果push的数值大于入口元素的数值，则将队列后端的数值弹出
        // 直到push的数值小于等于队列入口元素的数值为止
        // 这就保持了队列里面的数值是单调从大到小了
        void push(int value) {
            while(!que.empty() && value > que.back())
                que.pop_back();
            que.push_back(value);
        }
        // 查询当前队列最大值
        int front() {
            return que.front();
        }
    };
public:
    // 单调队列！
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MyQueue que;
        vector<int> result;
        // 滑动窗口初始化
        for(int i = 0; i < k; i++)
            que.push(nums[i]);
        result.push_back(que.front());
        // 滑动窗口开始移动
        for(int i = k; i < nums.size(); i++) {
            que.pop(nums[i - k]);
            que.push(nums[i]);
            result.push_back(que.front());
        }
        return result;
    }
};
// @lc code=end

