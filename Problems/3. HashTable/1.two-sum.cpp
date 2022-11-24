/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // 俩种方法：
        // 双指针法：如果数组有序
        // 哈希法：字面意思
        // key存元素，value存下标
        int len = nums.size();
        vector<int> ans;
        unordered_map<int, int> mp;
        // 我们只需要一次循环即可！
        for(int i = 0; i < len; ++i) {
            auto iter = mp.find(target - nums[i]);
            if(iter != mp.end())
                return {iter->second, i};
            mp.insert(pair<int, int>(nums[i], i));
        }
        return {};
    }
};
// @lc code=end

