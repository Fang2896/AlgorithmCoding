/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 */

/*
分析：
    左闭右开
    然后每次循环需要4个过程，→ ↓ ← ↑
    第一次循环每个过程的步数为n-1，第二次为n-2，以此类推
    直到步数为1为止！
*/

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int startX = 0, startY = 0; // 每次循环一个圈的起始位置
        int loop = n / 2;   // 矩阵中间值单独处理
        int mid = n / 2;    // 中间位置
        int count = 1, offset = 1, i, j;
        while(loop--) {
            i = startX, j = startY;
            // 模拟转圈,左闭右开
            // →
            for(j = startY; j < n - offset; j++)
                res[startY][j] = count++;
            // ↓
            for(i = startX; i < n - offset; i++)
                res[i][j] = count++;
            // ←
            for( ; j > startY; j--)
                res[i][j] = count++;
            // ↑
            for( ; i > startX; i--)
                res[i][j] = count++;
            startX++; startY++; offset++; 
        }
        if(n % 2)   // 奇数
            res[mid][mid] = count;
        return res;
    }
};
// @lc code=end

