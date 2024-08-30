//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
     
        int m=1000000000+7;
    int Ways(int n,vector<int>&dp)
    {
         if(n==0)
        {
            return 1;
        }
        if(n==1 || n==2)
        {
            return n;
        }
        
        if(dp[n]!=-1)
        {
            return dp[n]%m;
        }
        
        return dp[n]=(Ways(n-1,dp)%m+Ways(n-2,dp)%m)%m;
    }
    int countWays(int n)
    {
        // your code here
        vector<int>dp(n+1,-1);
        
     //   int m=1000000000+7;
        
        return Ways(n,dp);
        
       
    }
};



//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}

// } Driver Code Ends