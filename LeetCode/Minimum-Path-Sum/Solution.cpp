1class Solution {
2public:
3    int minPathSum(vector<vector<int>>& grid) {
4        int n=grid.size();
5        int m=grid[0].size();
6
7        vector<vector<int>>dp(n,vector<int>(m,0));
8
9        for(int i=0;i<n;i++)
10        {
11            for(int j=0;j<m;j++)
12            {
13                if(i==0 && j==0)
14                {
15                    dp[i][j]=grid[i][j];
16                }
17                else
18                {
19                    int up=i>0?dp[i-1][j]:INT_MAX;
20                    int left=j>0?dp[i][j-1]:INT_MAX;
21
22                    dp[i][j]=grid[i][j]+min(up,left);
23                }
24            }
25        }
26
27        return dp[n-1][m-1];
28
29    }
30};