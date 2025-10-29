class Solution {
public:
    
    int findUniquePaths(int i,int j,int m,int n,vector<vector<int>>&dp,vector<vector<int>>&grid)
    {
        if(i==m-1 && j==n-1)
        {
            return 1;
        }

        if(i<0 || j<0 || i==m || j==n) return 0;

        if(dp[i][j]!=-1) return dp[i][j];
        int v1=findUniquePaths(i+1,j,m,n,dp,grid);
        int v2=findUniquePaths(i,j+1,m,n,dp,grid);

        return dp[i][j]=v1+v2;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>grid(m,vector<int>(n,0));
        vector<vector<int>>dp(m,vector<int>(n,-1));

        return findUniquePaths(0,0,m,n,dp,grid);
    }
};