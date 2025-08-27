class Solution {
public:
    int mxpro=0;

    int totalProfit(vector<int>&prices,vector<vector<int>>&dp,int idx,int canBuy)
    {
        if(idx>=prices.size()) return 0;
        if(dp[idx][canBuy]!=-1) return dp[idx][canBuy];
        int buy=INT_MIN,nbuy=INT_MAX;

        if(canBuy)
        {
            buy=totalProfit(prices,dp,idx+1,!canBuy)-prices[idx];
        }
        else
        {
            buy=totalProfit(prices,dp,idx+2,!canBuy)+prices[idx];
        }
        nbuy=totalProfit(prices,dp,idx+1,canBuy);
        return dp[idx][canBuy]=mxpro+max(buy,nbuy);
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();

        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return totalProfit(prices,dp,0,1);
    }
};