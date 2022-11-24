/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] Ransom Note
 */

// @lc code=start
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mp;
        for(auto c : magazine) 
            mp[c]++;
        for(auto c : ransomNote) {
            if(mp.find(c) != mp.end()) {
                if(mp[c] == 0)
                    return false;
                else
                    mp[c]--;
            } else 
                return false;
        }
        return true;
    }
};
// @lc code=end

