class Solution {
public:
    int fun(string s1,string s2,int n,int m,vector<vector<int>>&dp)
    {
       /* if(i<0)
        {
            return j+1;
        }

        if(j<0)
        {
            return i+1;
        }

        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(s1[i]==s2[j])
        {
            return dp[i][j]=0+fun(s1,s2,i-1,j-1,dp);
        }

        return dp[i][j]=1+min(fun(s1,s2,i,j-1,dp),min(fun(s1,s2,i-1,j,dp),fun(s1,s2,i-1,j-1,dp)))*/

        for(int i=0;i<=n;i++)
        {
            dp[i][0]=i;
        }

        for(int j=0;j<=m;j++)
        {
            dp[0][j]=j;
        }

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1]==s2[j-1])
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
                }
            }
        }

        return dp[n][m];
    }
    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();

        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return fun(word1,word2,n,m,dp);
    }
};