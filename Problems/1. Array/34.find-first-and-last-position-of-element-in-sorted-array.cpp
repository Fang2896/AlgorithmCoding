/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int leftEdge = findLeftEdge(nums, target);
        int rightEdge = findRightEdge(nums, target);
        // case 1
        if(leftEdge == -2 || rightEdge == -2)
            return {-1, -1};
        // case 2
        if(rightEdge - leftEdge > 1)
            return {leftEdge, rightEdge - 1};
        return {-1,-1};
    }
private:
    // Find the LEFT edge of target(which dont include the target)
    int findLeftEdge(vector<int>& nums, int target) {
        auto left = nums.begin();
        auto right = nums.end();
        int leftEdge = -2;
        while(left != right) {
            auto mid = left + (right - left) / 2;
            if(*mid < target)
                left = mid + 1;
            else{
                right = mid;
                leftEdge = right - nums.begin();
            }
        }
        return leftEdge;
    }

    // Find the RIGHT edge of target(which dont include the target)
    int findRightEdge(vector<int>& nums, int target) {
        auto left = nums.begin();
        auto right = nums.end();
        int rightEdge = -2;
        while(left != right) {
            auto mid = left + (right - left) / 2;
            if(*mid > target)
                right = mid;
            else{
                left = mid + 1;
                rightEdge = right - nums.begin();
            }
        }
        return rightEdge;
    }
};
// @lc code=end

