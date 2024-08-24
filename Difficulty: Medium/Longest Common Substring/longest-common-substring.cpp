//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    int LCS(string str1,string str2,int n,int m)
    {
        int dp[n+1][m+1];
        
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0 || j==0)
                {
                dp[i][j]=0;
                }
            }
        }
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(str1[i-1]==str2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=0;
                }
            }
        }
        
        int mx=INT_MIN;
        
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                mx=max(mx,dp[i][j]);
            }
        }
        
        return mx;
    }
    int longestCommonSubstr(string str1, string str2) {
        // your code here
        
        int n=str1.length();
        int m=str2.length();
        
        return LCS(str1,str2,n,m);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2) << endl;
    }
}
// } Driver Code Ends