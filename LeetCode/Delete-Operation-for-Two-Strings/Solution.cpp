class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();

        vector<vector<int>>dp(n+1,vector<int>(m+1,0));

        for(int i=0;i<n;i++)
        {
            dp[i][m]=0;
        }
        for(int i=0;i<m;i++)
        {
            dp[n][i]=0;
        }

        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(word1[i]==word2[j])
                {
                    dp[i][j]=1+dp[i+1][j+1];
                }
                else
                {
                    dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
                }
            }
        }
        int len=dp[0][0];

        return (n-len)+(m-len);
    }
};