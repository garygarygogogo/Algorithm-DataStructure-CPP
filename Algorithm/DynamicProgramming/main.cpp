/*
在一个 m*n 的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于 0）。你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或者向下移动一格、直到到达棋盘的右下角。给定一个棋盘及其上面的礼物的价值，请计算你最多能拿到多少价值的礼物？

示例 1:
输入: 
[
  [1,3,1],
  [4,2,7],
  [3,1,1]
]
输出: 15
解释: 路径 1→4→2→7→1 可以拿到最多价值的礼物

提示：
0 < grid.length <= 200
0 < grid[0].length <= 200
*/
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int> > dp(m, vector<int>(n, 0));
        dp[0][0] = grid[0][0];
        for(int i = 1; i < m; ++i)
            dp[i][0] += dp[i-1][0] + grid[i][0];
        for(int j = 1; j < n; ++j)
            dp[0][j] += dp[0][j-1] + grid[0][j];     //初始化第一列和第一行

        for(int i = 1; i < m; ++i)    
        	for(int j = 1; j < n; ++j)
            	dp[i][j] = max(dp[i][j-1], dp[i-1][j]) + grid[i][j]; //这是递推式
        
        return dp[m-1][n-1];
    }
};
// 时间复杂度 O(MN) ： M, N 分别为矩阵行高、列宽
// 空间复杂度：O(n^2)