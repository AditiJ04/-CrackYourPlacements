1class Solution {
2public:
3
4    int findPath(int i,int j,vector<vector<int>>&dp,vector<vector<int>>&grid)
5    {
6        if(i==grid.size()-1 && j==grid[0].size()-1) return grid[i][j];
7
8        if(dp[i][j]!=-1) return dp[i][j];
9        int res=INT_MAX;
10        if((i+1)<grid.size()) {res=min(res,findPath(i+1,j,dp,grid));}
11        if((j+1)<grid[0].size()) {res=min(res,findPath(i,j+1,dp,grid));}
12
13        return dp[i][j]=grid[i][j]+res;
14    }
15    int minPathSum(vector<vector<int>>& grid) {
16
17        if(grid.empty() || grid[0].empty()) return 0;
18        int n=grid.size();
19        int m=grid[0].size();
20
21        vector<vector<int>>dp(n,vector<int>(m,-1));
22
23        return findPath(0,0,dp,grid);
24
25    }
26};