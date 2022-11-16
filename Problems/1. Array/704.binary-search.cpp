/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] Binary Search
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto beg = nums.begin(), end = nums.end();
        while(beg != end) {
            auto mid = beg + (end - beg) / 2;
            if (*mid < target) {
                beg = mid + 1;
            } else if (*mid > target) {
                end = mid;
            } else {
                return (mid - nums.begin());
            }
        }
        return -1;
    }
};
// @lc code=end

