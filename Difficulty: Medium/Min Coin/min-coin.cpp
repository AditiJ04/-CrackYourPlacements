//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int knapsack(vector<int>&nums,int amt,int n)
	{
	    int dp[n+1][amt+1];
	    
	    for(int i=0;i<=n;i++)
	    {
	        for(int j=0;j<=amt;j++)
	        {
	            if(i==0)
	            {
	                dp[i][j]=INT_MAX-1;
	            }
	            if(j==0)
	            {
	                dp[i][j]=0;
	            }
	            
	             if(i==1)
	            {
	            if(j%nums[i-1]==0)
	            {
	                dp[i][j]=j/nums[i-1];
	            }
	            else
	            {
	                dp[i][j]=INT_MAX;
	            }
	            }
	        }
	    }
	    
	    for(int i=1;i<=n;i++)
	    {
	        for(int j=1;j<=amt;j++)
	        {
	            if(nums[i-1]<=j)
	                {
	                    dp[i][j]=min(1+dp[i][j-nums[i-1]],dp[i-1][j]);
	                }
	                else
	                {
	                    dp[i][j]=dp[i-1][j];
	                }

	        }
	    }
	    
	    return dp[n][amt];
	}
	int MinCoin(vector<int>nums, int amount)
	{
	    // Code here
	    int n=nums.size();
	    if(knapsack(nums,amount,n)==INT_MAX-1)
	    {
	        return -1;
	    }
	    return knapsack(nums,amount,n);
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, amount;
		cin >> n >> amount;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.MinCoin(nums, amount);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends