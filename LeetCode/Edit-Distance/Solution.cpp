class Solution {
public:
    
    int minOperations(string word1,string word2,vector<vector<int>>&dp,int idx1,int idx2)
    {
        int n=word1.size();
        int m=word2.size();
       if (idx1 == word1.size()) return word2.size() - idx2;
if (idx2 == word2.size()) return word1.size() - idx1;
        

        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
        int o2=0,o3=0,o4=0;

        if(word1[idx1]==word2[idx2])
        {
            return dp[idx1][idx2]=minOperations(word1,word2,dp,idx1+1,idx2+1);
        }
        else
        {
            o2=minOperations(word1,word2,dp,idx1+1,idx2);
            o3=minOperations(word1,word2,dp,idx1,idx2+1);
            o4=minOperations(word1,word2,dp,idx1+1,idx2+1);

            return dp[idx1][idx2]=1+min({o4,o2,o3});
        }
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();

        vector<vector<int>>dp(n,vector<int>(m,-1));
        return minOperations(word1,word2,dp,0,0);
    }
};