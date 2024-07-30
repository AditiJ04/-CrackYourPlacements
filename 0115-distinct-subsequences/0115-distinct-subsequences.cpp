class Solution {
public:
    int match(int i,int j,string s,string t,vector<vector<int>>&dp)
    {
         if(j<0)
        {
            return 1;
        }

        if(i<0)
        {
            return 0;
        }

        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(s[i]==t[j])
        {
            return dp[i][j]=match(i-1,j-1,s,t,dp)+match(i-1,j,s,t,dp);
        }

        else
        {
        return dp[i][j]=match(i-1,j,s,t,dp);
        }
    }
    int numDistinct(string s, string t) {
        int i=s.size();
        int j=t.size();

        vector<vector<int>>dp(i,vector<int>(j,-1));
        return match(i-1,j-1,s,t,dp);
    }
};