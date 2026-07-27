1class Solution {
2public:
3    int minPathSum(vector<vector<int>>& grid) {
4        int n=grid.size();
5        int m=grid[0].size();
6
7        vector<vector<int>>dp(n,vector<int>(m,0));
8        dp[n-1][m-1]=grid[n-1][m-1];
9
10
11        for(int i=n-2;i>=0;i--)
12        {
13            dp[i][m-1]=grid[i][m-1]+dp[i+1][m-1];
14        }
15
16        for(int i=m-2;i>=0;i--)
17        {
18            dp[n-1][i]=grid[n-1][i]+dp[n-1][i+1];
19        }
20
21        for(int i=n-2;i>=0;i--)
22        {
23            for(int j=m-2;j>=0;j--)
24            {
25                int c1=dp[i+1][j];
26                int c2=dp[i][j+1];
27
28                dp[i][j]=min({c1,c2})+grid[i][j];
29            }
30        }
31
32        return dp[0][0];
33    }
34};