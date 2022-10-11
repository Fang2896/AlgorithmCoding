/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] Binary Search
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto left = nums.begin();
        auto right = nums.end();
        auto mid = left + (right - left) / 2;
        while(left != right){
            if(target < *mid)
                right = mid;
            else if(target > *mid)
                left = mid + 1;
            else
                return mid - nums.begin();
            
            mid = left + (right - left) / 2;
        }
        return -1;
    }
};
// @lc code=end

