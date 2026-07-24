1class Solution {
2public:
3    int uniquePaths(int m, int n) {
4        vector<vector<int>>dp(m,vector<int>(n,0));
5
6        dp[m-1][n-1]=1;
7
8        for(int i=m-1;i>=0;i--)
9        {
10            for(int j=n-1;j>=0;j--)
11            {
12                if((i+1)<m) dp[i][j]+=dp[i+1][j];
13                if((j+1)<n) dp[i][j]+=dp[i][j+1];
14            }
15        }
16
17        return dp[0][0];
18    }
19};