//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
  /*  int solve(vector<vector<int>>&mat,int i,int j,int &maxi)
    {
        if(i>=mat.size() || j>=mat[0].size())
        {
            return 0;
        }

        int diag=solve(mat,i+1,j+1,maxi);
        int right=solve(mat,i,j+1,maxi);
        int down=solve(mat,i+1,j,maxi);

        if(mat[i][j]==1)
        {
            int ans=1+min(diag,min(down,right));
            maxi=max(maxi,ans);
            return ans;
        }

        else
        {
            return 0;
        }
    }*/
    
    int solveTab(vector<vector<int>>&mat,int &maxi)
    {
        int n=mat.size();
        int m=mat[0].size();
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        
        for(int r=n-1;r>=0;r--)
        {
            for(int c=m-1;c>=0;c--)
            {
                int diag=dp[r+1][c+1];
                int right=dp[r][c+1];
                int down=dp[r+1][c];
                
                if(mat[r][c]==1)
                {
                    dp[r][c]=1+min(diag,min(down,right));
                    maxi=max(maxi,dp[r][c]);
                }
                else
                {
                    dp[r][c]=0;
                }
            }
        }
        
        return maxi;
        
    }
    
    int solveMem(vector<vector<int>>&mat,int i,int j,int &maxi,vector<vector<int>>&dp)
    {
        if(i>=mat.size() || j>=mat[0].size())
        {
            return 0;
        }
        
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }

        int diag=solveMem(mat,i+1,j+1,maxi,dp);
        int right=solveMem(mat,i,j+1,maxi,dp);
        int down=solveMem(mat,i+1,j,maxi,dp);

        if(mat[i][j]==1)
        {
            dp[i][j]=1+min(diag,min(down,right));
            maxi=max(maxi,dp[i][j]);
            return dp[i][j];
        }

        else
        {
            return 0;
        }
    }
    
    
    int maxSquare(vector<vector<int>>& mat) {
        // code here
        int maxi=0;
        
        int n=mat.size();
        int m=mat[0].size();
        
     //   vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        solveTab(mat,maxi);

        return maxi;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for (int i = 0; i < n * m; i++)
            cin >> mat[i / m][i % m];

        Solution ob;
        cout << ob.maxSquare(mat) << "\n"
             << "~\n";
    }
    return 0;
}
// } Driver Code Ends