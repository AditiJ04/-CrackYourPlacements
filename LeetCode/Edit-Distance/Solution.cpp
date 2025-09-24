class Solution {
public:

    int findMinOperations(string word1,string word2,vector<vector<int>>&dp,int i1,int i2)
    {
        if(i1<0) return i2+1;
        if(i2<0) return i1+1;

        if(dp[i1][i2]!=-1) return dp[i1][i2];
        if(word1[i1]==word2[i2])
        {
            return findMinOperations(word1,word2,dp,i1-1,i2-1);
        }
        int c1=findMinOperations(word1,word2,dp,i1,i2-1);
        int c2=findMinOperations(word1,word2,dp,i1-1,i2);
        int c3=findMinOperations(word1,word2,dp,i1-1,i2-1);

        return dp[i1][i2]=1+min({c1,c2,c3});
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();

        vector<vector<int>>dp(n,vector<int>(m,-1));
        return findMinOperations(word1,word2,dp,n-1,m-1);
    }
};