class Solution {
public:
    int dp[46];
    
    int totalStairs(int n)
    {
        if(n<=1) return 1;
        if(dp[n]!=-1) return dp[n];

        return dp[n]=totalStairs(n-1)+totalStairs(n-2);
    }
    int climbStairs(int n) {
        if(n<=1) return 1;

        memset(dp,-1,sizeof(dp));

        return totalStairs(n);
    
    }
};