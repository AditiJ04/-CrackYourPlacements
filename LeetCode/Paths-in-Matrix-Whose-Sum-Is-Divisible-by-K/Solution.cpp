1class Solution {
2public:
3    int mod = 1e9 + 7;
4    int n, m;
5    int dfs(int i, int j, vector<vector<int>>& grid,vector<vector<vector<int>>>&dp, int k, int sum) {
6        if (i == n || j == m)
7            return 0;
8
9        sum= (sum+grid[i][j])%k;
10        int v=sum;
11        if (i == n - 1 && j == m - 1) {
12            if (sum % k == 0)
13                return 1;
14            return 0;
15        }
16        if(dp[i][j][v]!=-1) return dp[i][j][v];
17
18        long long v1=dfs(i+1,j,grid,dp,k,sum);
19        long long v2=dfs(i,j+1,grid,dp,k,sum);
20
21        long long ways=(v1+v2)%mod;
22        dp[i][j][v]=(int) ways;
23        
24        return dp[i][j][v];
25    }
26    int numberOfPaths(vector<vector<int>>& grid, int k) {
27        n = grid.size();
28        m = grid[0].size();
29
30        vector<vector<vector<int>>> dp(
31            n, vector<vector<int>>(m, vector<int>(k,-1) 
32                                   ));
33        int cnt=dfs(0, 0, grid,dp, k, 0);
34
35        return cnt;
36    }
37};