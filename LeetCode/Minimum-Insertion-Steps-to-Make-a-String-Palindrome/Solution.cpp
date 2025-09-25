class Solution {
public:
    int minInsertions(string s) {
        int n=s.size();

        vector<vector<int>>dp(n,vector<int>(n,0));

        for(int len=2;len<=n;len++)
        {
            for(int si=0;si<n-len+1;si++)
            {
                int ei=si+len-1;

                if(s[si]==s[ei])
                {
                    dp[si][ei]=dp[si+1][ei-1];
                }
                else
                {
                    dp[si][ei]=1+min(dp[si+1][ei],dp[si][ei-1]);
                }
            }
        }

        return dp[0][n-1];
    }
};