//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int m=1000000000+7;
	int CountSubsets(int arr[],int n,int sum,vector<vector<int>>&dp)
	{
	    if(sum==0 && n==0)
	    {
	        return 1;
	    }
	    if(n==0)
	    {
	        return 0;
	    }
	    
	    if(dp[n][sum]!=-1)
	    {
	        return dp[n][sum];
	    }
	    int a,b;
	    if(arr[n-1]<=sum)
	    {
	    a=CountSubsets(arr,n-1,sum-arr[n-1],dp)%m;
	    b=CountSubsets(arr,n-1,sum,dp)%m;
	    
	    return dp[n][sum]=(a+b)%m;
	    }
	   return dp[n][sum]=CountSubsets(arr,n-1,sum,dp)%m;
	}
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
       return CountSubsets(arr,n,sum,dp)%m;
        
	}
	  
};


//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends