/*

eg 1:
input: 
[
  [1,3,1],
  [4,2,7],
  [3,1,1]
]
output: 15
why: path 1→4→2→7→1 is most valueable

hint：
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
            dp[0][j] += dp[0][j-1] + grid[0][j];     // initialize 1st row and 

        for(int i = 1; i < m; ++i)    
        	for(int j = 1; j < n; ++j)
            	dp[i][j] = max(dp[i][j-1], dp[i-1][j]) + grid[i][j]; // recursive equation
        
        return dp[m-1][n-1];
    }
};
// time O(MN) ： M, N row and col size
// space：O(n^2)