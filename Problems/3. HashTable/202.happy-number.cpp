/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] Happy Number
 */

// @lc code=start
class Solution {
public:
// 自己的版本优化下
/* 函数合并后的结果
Your runtime beats 49.89 % of cpp submissions
Your memory usage beats 41.04 % of cpp submissions (6.1 MB)
*/


    int getSum(int n) {
        int sum = 0;
        while(n) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
            // 先解决一个问题，如何拆分一个数的各个位
        unordered_set<int> mp;   // 用来存储出现过的sumS
        int sumS = getSum(n);
        // 跳出循环的俩条件：1. sumS=1，2. 发现重复数字！
        while(sumS != 1 && mp.find(sumS) == mp.cend()) {
            mp.insert(sumS);
            sumS = getSum(sumS);
        }
        if(sumS == 1)
            return true;
        else
            return false;
    }

};
// @lc code=end

/* 自己写的 
Your runtime beats 6.3 % of cpp submissions
Your memory usage beats 5 % of cpp submissions (6.8 MB)
感觉是因为模块化，所以速度更慢

class Solution {
public:
    // 用来分解一个数的digits
    vector<int> digitSep(int n) {
        vector<int> digits;
        int temp;
        while(n != 0) {
            temp = n % 10;
            digits.emplace_back(temp);
            n = n / 10;
        }
        return digits;
    }
    int sumOfSquare(vector<int> vec) {
        int sumS = 0;
        for(int num : vec) {
            sumS += num*num;
        }
        return sumS;
    }

    bool isHappy(int n) {
            // 先解决一个问题，如何拆分一个数的各个位
        unordered_set<int> mp;   // 用来存储出现过的sumS
        vector<int> temp = digitSep(n);
        int sumS = sumOfSquare(temp);
        // 跳出循环的俩条件：1. sumS=1，2. 发现重复数字！
        while(sumS != 1 && mp.find(sumS) == mp.cend()) {
            mp.insert(sumS);
            temp = digitSep(sumS);
            sumS = sumOfSquare(temp);
        }
        if(sumS == 1)
            return true;
        else
            return false;
    }
};
*/


/* 
// 代码随想录的版本,将我的俩函数合并成了一个
/*
Your runtime beats 49.89 % of cpp submissions
Your memory usage beats 61.44 % of cpp submissions (6.1 MB)
*/
/*
int getSum(int n) {
    int sum = 0;
    while(n) {
        sum += (n % 10) * (n % 10);
        n /= 10;
    }
    return sum;
}
bool isHappy(int n) {
    unordered_set<int> setM;
    while(1) {
        int sum = getSum(n);
        if(sum == 1)
            return true;
        if(setM.find(sum) != setM.cend())
            return false;
        else   
            setM.insert(sum);
        n = sum;
    }
}
*/