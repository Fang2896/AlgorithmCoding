/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] Intersection of Two Arrays
 */

// @lc code=start
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // 也可用unordered_set来做
        // 因为set中的元素是唯一的！
        // 输出结果中的每个元素一定是唯一的，
        // 也就是说输出的结果的去重的， 同时可以不考虑输出结果的顺序
        // 故考虑set，set和multiset底层实现是红黑树，
        // unordered_set实现是哈希表
        unordered_set<int> ans; // 用set存放结果！
        // 学习这种初始化！！！容器一般都能可以直接用范围初始化
        unordered_set<int> nums_set(nums1.begin(), nums1.end());
        for(int num : nums2) {
            if(nums_set.find(num) != nums_set.end()) 
                ans.insert(num);
        }
        return vector<int>(ans.begin(), ans.end());
    }
};
// @lc code=end

/* 自己用unodered_map来做的
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
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
                mp[nums2[i]] = 0;   // 置0，因为不能有重复
            }
        }
        return ans;
    }
};

*/