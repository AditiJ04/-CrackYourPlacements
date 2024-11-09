//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    int MaxProfit(int W,int val[],int wt[],int idx,vector<vector<int>>&dp)
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
           return dp[idx][W]=MaxProfit(W,val,wt,idx-1,dp);
        }
        
        int take=val[idx]+MaxProfit(W-wt[idx],val,wt,idx,dp);
        int ntake=MaxProfit(W,val,wt,idx-1,dp);
        
        return dp[idx][W]=max(take,ntake);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>>dp(N,vector<int>(W+1,-1));
        return MaxProfit(W,val,wt,N-1,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends