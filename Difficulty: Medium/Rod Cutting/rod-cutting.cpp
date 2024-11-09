//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  
    int dp[1001][1001];
      
    int MaxProfit(int W,int val[],int wt[],int idx)
    {
        if(idx<0 || W<=0)
        {
            return 0;
        }
        
        if(dp[idx][W]!=-1)
        {
            return dp[idx][W];
        }
        
        if(wt[idx]>W)
        {
           return dp[idx][W]=MaxProfit(W,val,wt,idx-1);
        }
        
        int take=val[idx]+MaxProfit(W-wt[idx],val,wt,idx);
        int ntake=MaxProfit(W,val,wt,idx-1);
        
        return dp[idx][W]=max(take,ntake);
    }
    int cutRod(int price[], int n) {
        //code here
        
        int len[n];
        
        for(int i=0;i<n;i++)
        {
            len[i]=i+1;
        }
         
        memset(dp,-1,sizeof(dp));
        return MaxProfit(n,price,len,n-1);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends