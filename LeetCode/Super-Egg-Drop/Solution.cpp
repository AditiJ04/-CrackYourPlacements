class Solution {
public:

    int solve(int k,int n,vector<vector<int>>&dp)
    {
        if(n==0 || n==1) return n;
        if(k==1) return n;

        if(dp[k][n]!=-1) return dp[k][n];

        int l=1,h=n;
        int ans=INT_MAX;

        while(l<=h)
        {
            int mid=(l+h)/2;

            int b=solve(k-1,mid-1,dp);
            int nb=solve(k,n-mid,dp);

            int tmp=1+max(b,nb);
            ans=min(ans,tmp);

            if(b>nb)
            {
                h=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }

        return dp[k][n]=ans;
    }
    int superEggDrop(int k, int n) {
        vector<vector<int>>dp(k+1,vector<int>(n+1,-1));

        return solve(k,n,dp);
    }
};