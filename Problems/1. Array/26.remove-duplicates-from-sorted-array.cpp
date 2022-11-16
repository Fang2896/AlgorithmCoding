/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // 同理，双指针法
        int slowIndex = 0, flag = 0;
        for(int fastIndex = 1; fastIndex < nums.size(); fastIndex++) {
            if(nums[slowIndex] != nums[fastIndex]) {
                nums[++slowIndex] = nums[fastIndex];
            }
        }
        return slowIndex + 1;
    }
};
// @lc code=end

