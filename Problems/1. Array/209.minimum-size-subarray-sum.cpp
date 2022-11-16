/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int result = INT32_MAX, sum = 0, i = 0, subLength = 0;
        for(int j = 0; j<nums.size(); j++) {
            sum += nums[j];
            while(sum >= target) {
                subLength = (j - i + 1);
                // 记录最小
                result = result < subLength ? result : subLength;
                // 左边收缩
                sum -= nums[i++];
            }
        }
        // 防止特殊情况出现
        return result == INT32_MAX ? 0 : result;
    }
};
// @lc code=end

