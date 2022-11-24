/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // 第二个思路，仨指针法
        // 这个思路也可以用在2sum中，但是2sum那边用哈希更方便
        // 3sum用指针法就更简单了，主要是去重更加简单
        vector<vector<int>> ans;
        int len = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < len; i++) {
            if(nums[i] > 0)
                return ans;
            if(i > 0 && nums[i] == nums[i-1])   // 这个与上一个相同，直接pass
                continue;
            int left = i + 1;
            int right = len - 1;
            while(right > left) {
                // 去重的时候注意别忽略了0，0，0的情况！
                if(nums[i] + nums[left] + nums[right] > 0) right--;
                else if(nums[i] + nums[left] + nums[right] < 0) left++;
                else {  // 等于0的情况
                    ans.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    while(right > left && nums[right] == nums[right - 1]) right--;
                    while(right > left && nums[left] == nums[left + 1]) left++;
                    // 找到答案后，俩边收缩
                    right--;
                    left++;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

/* 哈希表做法
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // 第一个思路：哈希表法
        // 难点在于不能有重复的三元组！
        // 而且O也不高
        // Your runtime beats 5.02 % of cpp submissions
        // Your memory usage beats 5.05 % of cpp submissions (261.7 MB)
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        // 找出a+b+c=0
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] > 0)
                break;
            if(i > 0 && nums[i] == nums[i-1]) { // 三元组元素a去重
                continue;
            }
            // 上面是固定了第一个值，然后用二位哈希去做，但是注意要去重！
            unordered_set<int> set;
            for(int j = i + 1; j < nums.size(); j++) {
                if(j > i + 2
                        && nums[j] == nums[j-1]
                        && nums[j-1] == nums[j-2]) {    // 三元组元素b去重
                    continue;
                }
                int c = 0 - (nums[i] + nums[j]);
                if(set.find(c) != set.end()) {
                    ans.push_back({nums[i], nums[j], c});
                    set.erase(c);   // 三元组元素c去重
                } else {
                    set.insert(nums[j]);
                }
            }
        }
        return ans;
    }
};

*/