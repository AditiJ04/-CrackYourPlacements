1class Solution {
2public:
3    int minSumPathUtil(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp) {
4    // Base cases
5    if (i == 0 && j == 0)
6        return matrix[0][0]; // If we are at the top-left corner, the minimum path sum is the value at (0, 0)
7    if (i < 0 || j < 0)
8        return INT_MAX; // If we go out of bounds, return a large value to avoid considering this path
9    if (dp[i][j] != -1)
10        return dp[i][j]; // If the result is already computed, return it
11
12    // Calculate the minimum sum path by considering moving up and moving left
13    int cost= matrix[i][j] + min(minSumPathUtil(i - 1, j, matrix, dp),minSumPathUtil(i, j - 1, matrix, dp));
14
15    // Store the result in the DP table and return it
16    return dp[i][j] = cost;
17}
18    int minPathSum(vector<vector<int>>& grid) {
19
20        int n=grid.size();
21        int m=grid[0].size();
22        vector<vector<int>> dp(n, vector<int>(m, -1)); // DP table to memoize results
23    return minSumPathUtil(n - 1, m - 1, grid, dp); 
24    }
25};