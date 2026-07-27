1class Solution {
2public:
3    int minPathSum(vector<vector<int>>& grid) {
4        if (grid.empty() || grid[0].empty()) return 0;
5        int n = grid.size();
6        int m = grid[0].size();
7
8        vector<vector<int>> dp(n, vector<int>(m, 0));
9        dp[n-1][m-1] = grid[n-1][m-1];
10
11        // last row
12        for (int j = m - 2; j >= 0; j--) {
13            dp[n-1][j] = dp[n-1][j+1] + grid[n-1][j];
14        }
15        // last column
16        for (int i = n - 2; i >= 0; i--) {
17            dp[i][m-1] = dp[i+1][m-1] + grid[i][m-1];
18        }
19
20        // fill rest
21        for (int i = n - 2; i >= 0; i--) {
22            for (int j = m - 2; j >= 0; j--) {
23                dp[i][j] = min(dp[i+1][j], dp[i][j+1]) + grid[i][j];
24            }
25        }
26
27        return dp[0][0];
28    }
29};
30