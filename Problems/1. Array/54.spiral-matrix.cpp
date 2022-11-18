/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // 先考虑特殊情况！
        if(matrix.size() == 0 || matrix[0].size() == 0) 
            return {};
        int rows = matrix.size(), columns = matrix[0].size();
        int total = rows * columns;
        vector<int> res(total); // 存放结果
        int startX = 0, startY = 0;
        int loop = min(rows, columns) / 2;
        int mid = min(rows, columns) / 2;
        // 若mid为偶数，则不需要考虑中间行/列/值
        // 若mid为奇数   且rows更小，则考虑中间行
        //              且columns更小，则考虑中间列
        int count = 0, offset = 1;
        int i, j;
        while(loop--) {
            i = startX, j = startY;
            for(j = startY; j < startY + columns - offset; j++) 
                res[count++] = matrix[startX][j];
            for(i = startX; i < startX + rows - offset; i++)
                res[count++] = matrix[i][j];
            for( ; j > startY; j--)
                res[count++] = matrix[i][j];
            for( ; i > startX; i--)
                res[count++] = matrix[i][startY];
            startX++, startY++;
            offset+=2;  // 控制下一个循环的遍历边长的offset
        }
        if(min(rows, columns) % 2) {    // 若有残留行/列
            if(rows > columns) {        // 残留的是列
                for(int i = mid; i < mid + rows - columns + 1; i++)
                    res[count++] = matrix[i][mid];
            } else {
                for(int i = mid; i < mid + columns - rows + 1; i++)
                    res[count++] = matrix[mid][i];
            }
        }
        return res;
    }
};
// @lc code=end

