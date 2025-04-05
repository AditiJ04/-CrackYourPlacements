//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
  int dp[1001][1001]; // adjust size according to constraints
int res;

int solve(string& s1, string& s2, int i, int j) {
    if (i == 0 || j == 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    solve(s1, s2, i - 1, j);   // explore other subproblems
    solve(s1, s2, i, j - 1);   // explore other subproblems

    if (s1[i - 1] == s2[j - 1]) {
        dp[i][j] = 1 + solve(s1, s2, i - 1, j - 1);
        res = max(res, dp[i][j]);
    } else {
        dp[i][j] = 0;
    }

    return dp[i][j];
}
    int longestCommonSubstr(string& s1, string& s2) {
        // your code here
        
    int n = s1.length();
    int m = s2.length();
    res = 0;
    memset(dp, -1, sizeof(dp));

    solve(s1, s2, n, m);
    return res;
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

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends