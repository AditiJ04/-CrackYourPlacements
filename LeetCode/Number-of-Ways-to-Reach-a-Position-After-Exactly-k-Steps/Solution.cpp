class Solution {
public:
    int mod=1e9+7;

    int f(int s,int i,int j,int k,int e,vector<vector<int>>&dp)
    {
        if(i==k && j==e) return 1;
        if(i==k && j!=e) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int l=0,r=0;
        l=f(s,i+1,j-1,k,e,dp);
        r=f(s,i+1,j+1,k,e,dp);

        return dp[i][j]=(l+r)%mod;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        vector<vector<int>>dp(k+1,vector<int>(10000,-1));

        startPos=startPos+1000;
        endPos=endPos+1000;

        return f(startPos,0,startPos,k,endPos,dp)%mod;
    }
};