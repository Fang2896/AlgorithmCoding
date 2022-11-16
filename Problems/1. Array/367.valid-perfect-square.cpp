/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] Valid Perfect Square
 */

// @lc code=start
class Solution {
public:
    bool isPerfectSquare(int num) {
        // 二分解法
        // 核心思想，在1到num/2中找是否有数的平方等于num
        if (num == 1)
            return true;
        int min = 0, max = num / 2;
        while(min <= max) {
            int mid = min + (max - min) / 2;
            long long temp = (long)mid*mid;
            if (temp == num)
                return true;
            else if (temp < num)
                min = mid + 1;
            else
                max = mid - 1;
        }
        return false;
    }
};
// @lc code=end


/* 前n个奇数的和等于n的平方解法：
class Solution {
public:
    bool isPerfectSquare(int num) {
        long long total = 0;
        int i = 1;
        while(total < num) {
            total += (2*(i++) - 1);
        }
        if(total == num)
            return true;
        else
            return false;
    }
};
*/

