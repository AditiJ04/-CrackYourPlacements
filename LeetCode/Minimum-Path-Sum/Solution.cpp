1class Solution {
2public:
3
4    int findMin(vector<vector<int>>&grid,vector<vector<int>>&dp,int i,int j,int n,int m)
5    {
6        if(i==n-1 && j==m-1) return grid[i][j];
7
8        if(dp[i][j]!=-1) return dp[i][j];
9
10        int c1=0,c2=0;
11
12        int res=INT_MAX;
13        if(i+1<n) res=min(res,findMin(grid,dp,i+1,j,n,m));
14        if(j+1<m) res=min(res,findMin(grid,dp,i,j+1,n,m));
15
16        return dp[i][j]=grid[i][j]+res;
17    }
18    int minPathSum(vector<vector<int>>& grid) {
19        int n=grid.size();
20        int m=grid[0].size();
21
22        vector<vector<int>>dp(n,vector<int>(m,-1));
23
24        return findMin(grid,dp,0,0,n,m);
25    }
26};