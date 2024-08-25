//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		
	public:
	int Sum(int arr[],int n,int idx,int prev,vector<vector<int>>&dp)
	{
	    if(idx==n)
	    {
	        return 0;
	    }
	    if(dp[idx][prev+1]!=-1)
	    {
	        return dp[idx][prev+1];
	    }
	    int sum1=0;
	    int sum2=0;
	    if(prev==-1 || arr[idx]>arr[prev])
	    {
	        sum1=arr[idx]+Sum(arr,n,idx+1,idx,dp);
	    }
	    
	    sum2=Sum(arr,n,idx+1,prev,dp);
	    return dp[idx][prev+1]=max(sum1,sum2);
	}
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
	    return Sum(arr,n,0,-1,dp);
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends