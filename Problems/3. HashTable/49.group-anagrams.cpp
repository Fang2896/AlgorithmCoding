/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 为啥要用数组作为key呢？直接将string用作数组频率！
        /* 
            优点：简单明了
            缺点：要是有一个字母出现超过256 - 'a'次，则会溢出！
            可能发生错误！
        */
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> ss;
        for(auto &str : strs) {
            string s = string(26, '0'); // 频率string
            for(auto &c : str) 
                s[c - 'a'] ++;
            ss[s].emplace_back(str);
        }
        for(auto &c : ss)
            ans.emplace_back(c.second);
        return ans;
    }
};
// @lc code=end


/* 用string计算对应的频率数组，然后用频率数组来作为key来哈希！
// 亮点在于对lambda 的用法
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 使用数组来作为key！因为只要记录下每一个str的每个字母出现次数即可
        // 即key的类型为array<int, 26>
        // 用俩个lambda函数来实现自定义的，以array为key的哈希函数！
        auto arrayHash = [fn = hash<int>{}] 
            (const array<int, 26>& arr) -> size_t {
                return accumulate(arr.begin(), arr.end(), 0u, 
                    [&](size_t acc, int num) {
                        return (acc << 1) ^ fn(num);    // 这个我还没搞懂？？？？
                    });
        };
        unordered_map<array<int, 26>, vector<string>, decltype(arrayHash)> 
            mp(0, arrayHash);
        // 遍历每一个string，计算出key数组，然后emplace进结果去
        for(string& str : strs) {
            array<int, 26> counts{};
            int length = str.length();
            for(int i = 0; i < length; ++i)
                counts[str[i] - 'a']++;
            mp[counts].emplace_back(str);
        }
        vector<vector<string>> ans;
        for(auto it = mp.begin(); it != mp.end(); ++it) {
            ans.emplace_back(it->second);
        }
        return ans;
    }
};

*/




/* ================================ */
/* 以排序好的字符串来作为key使用
O(nklog⁡k) O(nk)

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 将anagram分组！
        // 以排序为key来识别相同组
        unordered_map<string, vector<string>> mp;
        for(string& str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            mp[key].emplace_back(str);
        }
        vector<vector<string>> ans;
        for(auto it = mp.begin(); it!=mp.end(); ++it) 
            ans.emplace_back(it->second);
        return ans;
    }
};
*/