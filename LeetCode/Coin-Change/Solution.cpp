class Solution {
public:
    int Coin(vector<int>&coins,int amount,int idx,vector<vector<int>>&dp)
    {
        if(amount==0)
        {
            return 0;
        }

        if(idx<0 || amount<0)
        {
            return INT_MAX-1;
        }
        if(dp[idx][amount]!=-1)
        {
            return dp[idx][amount];
        }
        int one=Coin(coins,amount,idx-1,dp);
        int two=1+Coin(coins,amount-coins[idx],idx,dp);
        return dp[idx][amount]=min(one,two);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();

        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans=Coin(coins,amount,n-1,dp);

        return (ans<INT_MAX-1)?ans:-1;
    }
};