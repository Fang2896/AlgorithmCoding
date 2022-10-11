/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] Search Insert Position
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        auto beg = nums.begin();
        auto left = beg;
        auto right = nums.end();
        while(left != right){
            auto middle = left + (right - left) / 2;
            if(*middle < target)
                left = middle + 1;
            else if(*middle > target)
                right = middle;
            else
                return middle - beg;
        }
        return right - beg;
    }
};
// @lc code=end

