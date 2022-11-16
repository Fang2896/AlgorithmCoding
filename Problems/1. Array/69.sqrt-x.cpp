/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        if(x == 1)
            return 1;   // 极端例子
        int min = 0, max = x / 2, ans = -1;
        while(min <= max) {
            int mid = min + (max - min) / 2;
            if((long long)mid * mid <= x) {
                ans = mid;
                min = mid + 1;
            } else {
                max = mid - 1;
            }
        }
        return ans;
    }
};
// @lc code=end

