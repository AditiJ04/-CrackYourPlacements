class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();

        vector<vector<int>>dp(n,vector<int>(amount+1,-1));

        for(int i=0;i<=amount;i++)
        {
            if(i%coins[0]==0)
            {
                dp[0][i]=i/coins[0];
            }
            else
            {
                dp[0][i]=INT_MAX;
            }
        }

        for(int idx=1;idx<n;idx++)
        {
            for(int t=0;t<=amount;t++)
            {
                int ntake=dp[idx-1][t];

                int take=INT_MAX;

                if(t-coins[idx]>=0)
                {
                    int val=dp[idx][t-coins[idx]];
                    if(val!=INT_MAX)
                    {
                        take=1+val;
                    }
                }

                dp[idx][t]=min(take,ntake);
            }
        }

        int ans=dp[n-1][amount];

        if(ans==INT_MAX) return -1;

        return ans;
    }
};