class Solution {
public:

    int minCoins(vector<int>&coins,int amount,vector<vector<int>>&dp,int idx)
    {
        if(idx==coins.size() && amount!=0) return INT_MAX;
        if(amount==0)
        {
            return 0;
        }
        if(dp[amount][idx]!=-1) return dp[amount][idx];
        int take=INT_MAX,ntake;

        if(coins[idx]<=amount)
        {
            int val=minCoins(coins,amount-coins[idx],dp,idx);
            if(val!=INT_MAX)
            {
                take=1+val;
            }
        }
        ntake=minCoins(coins,amount,dp,idx+1);

        return dp[amount][idx]=min(take,ntake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();

        vector<vector<int>>dp(amount+1,vector<int>(n+1,-1));
        int tcoins=minCoins(coins,amount,dp,0);

        return tcoins==INT_MAX?-1:tcoins;
    }
};