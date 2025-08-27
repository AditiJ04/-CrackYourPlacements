class Solution {
public:

    int mxpro=0;
    int profitEarned(vector<int>&prices, vector<vector<vector<int>>>&dp,int idx,int canbuy,int trans)
    {
        int n=prices.size();

        if(idx==n || trans<=0) return 0;
        if(dp[idx][canbuy][trans]!=-1) return dp[idx][canbuy][trans];
        int buy=INT_MAX,nbuy=INT_MAX;

        if(canbuy)
        {
            buy=profitEarned(prices,dp,idx+1,!canbuy,trans)-prices[idx];
        }
        else
        {
            buy=prices[idx]+profitEarned(prices,dp,idx+1,!canbuy,trans-1);
        }
        nbuy=profitEarned(prices,dp,idx+1,canbuy,trans);
        return dp[idx][canbuy][trans]=mxpro+max(buy,nbuy);
    }
    int maxProfit(int k,vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n + 1,vector<vector<int>>(2, vector<int>(k+1, -1) ));
        return profitEarned(prices,dp,0,1,k);
    }
};