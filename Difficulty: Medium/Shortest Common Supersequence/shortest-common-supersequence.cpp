//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
  
     int findSCS(string str1,string str2,int n,int m,vector<vector<int>>&dp)
    {
        if(n==0 || m==0)
        {
            return n+m;
        }
        
        if(dp[n][m]!=-1)
        {
            return dp[n][m];
        }
        if(str1[n-1]==str2[m-1])
        {
            return dp[n][m]=1+findSCS(str1,str2,n-1,m-1,dp);
        }

        return dp[n][m]=1+min(findSCS(str1,str2,n-1,m,dp),findSCS(str1,str2,n,m-1,dp));
    }
    // Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string &s1, string &s2) {
        // code here
        int n=s1.size();
        int m=s2.size();
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

        int scs=findSCS(s1,s2,n,m,dp);

        return scs;
    }
};


//{ Driver Code Starts.

int main() {

    int t;

    // taking total testcases
    cin >> t;
    while (t--) {
        string X, Y;
        // taking String X and Y
        cin >> X >> Y;

        // calling function shortestCommonSupersequence()
        Solution obj;
        cout << obj.shortestCommonSupersequence(X, Y) << endl;
    }
    return 0;
}

// } Driver Code Ends