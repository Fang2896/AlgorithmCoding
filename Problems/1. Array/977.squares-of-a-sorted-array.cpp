/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] Squares of a Sorted Array
 */

// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // 双指针法，找边界并合并
        int neg = -1, n = nums.size();
        // 找分界点，0到neg为负数，其余为非负数
        for(int i = 0; i < n; i++) {
            if(nums[i] < 0)
                neg = i;
            else
                break;
        }
        vector<int> ans;
        int i = neg, j = neg + 1;
        // 开始合并， 先考虑neg仍然为-1的情况，即全部都正数
        while(i >= 0 || j < n) {
            if(i < 0) { // 全为正数的情况
                ans.push_back(nums[j] * nums[j]);
                ++j;
            } else if ( j == n) { // 全为负数的情况
                ans.push_back(nums[i] * nums[i]);
                --i;
            } else if (nums[i] * nums[i] < nums[j] * nums[j]) {
                ans.push_back(nums[i] * nums[i]);
                --i;
            } else {
                ans.push_back(nums[j] * nums[j]);
                ++j;
            }
        }
        return ans;
    }
};
// @lc code=end

// 双指针逆序法
/*
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // 双指针法，左右各两个指针
        int n = nums.size();
        vector<int> ans(n);
        for(int i = 0, j =  n-1, pos = n -1; i<= j; ) {
            if(nums[i] * nums[i] > nums[j] * nums[j]) {
                ans[pos] = nums[i] * nums[i];
                ++i;
            } else {
                ans[pos] = nums[j] * nums[j];
                --j;
            }
            --pos;
        }
        return ans;
    }
};
*/


