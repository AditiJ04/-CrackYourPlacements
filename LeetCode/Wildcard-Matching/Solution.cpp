class Solution {
public:

    bool tab(string s,string p)
    {

        int n=s.size();
        int m=p.size();

        vector<vector<int>>dp(n+1,vector<int>(m+1,0));

        dp[0][0]=true;

        for(int j=1;j<=m;j++)
        {
            bool flg=true;
            for(int k=1;k<=j;k++)
            {
                if(p[k-1]!='*')
                {
                    flg=false;
                    break;
                }
            }
            dp[0][j]=flg;
        }

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==p[j-1] || p[j-1]=='?')
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(p[j-1]=='*')
                {
                    dp[i][j]=dp[i-1][j] || dp[i][j-1];
                }
                else
                {
                    dp[i][j]=false;
                }
            }
        }

        return dp[n][m];
    }
    /*bool solve(string s,string p,int i,int j, vector<vector<int>>&dp)
    {
        if(i==0 && j==0)
        {
            return true;
        }

        if(i>0 && j==0)
        {
            return false;
        }

        if(i==0 && j>0)
        {
            for(int k=1;k<=j;k++)
            {
                if(p[k-1]!='*')
                {
                    return false;
                }
            }

            return true;
        }

        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }

        if(s[i-1]==p[j-1] || p[j-1]=='?')
        {
            return dp[i][j]=solve(s,p,i-1,j-1,dp);
        }

        else if(p[j-1]=='*')
        {
            return dp[i][j]=solve(s,p,i,j-1,dp) || solve(s,p,i-1,j,dp);
        }

        else
        {
            return false;
        }
    }*/
    bool isMatch(string s, string p) {

        int n=s.size();
        int m=p.size();

      //  vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
       // return solve(s,p,s.size(),p.size(),dp);
       return tab(s,p);
    }
};