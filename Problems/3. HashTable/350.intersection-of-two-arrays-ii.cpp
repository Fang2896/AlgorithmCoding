/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] Intersection of Two Arrays II
 */

// @lc code=start
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // 思路，哈希表，先用哈希表存储nums1中的状态，再匹配nums2
        unordered_map<int, int> mp;
        vector<int> ans;
        int len1 = nums1.size(), len2 = nums2.size();
        // 为nums1建立哈希表
        for(int i = 0; i < len1; ++i)
            ++mp[nums1[i]];
        for(int i = 0; i < len2; ++i) {
            if(mp[nums2[i]] > 0) {  // 说明有交集
                ans.emplace_back(nums2[i]);
                --mp[nums2[i]];   // 置0，因为不能有重复
            }
        }
        return ans;
    }
};
// @lc code=end

