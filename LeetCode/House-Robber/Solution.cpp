class Solution {
public:
    int amount(vector<int>&nums,vector<int>&dp,int idx)
    {
       if(idx>=nums.size())
       {
        return 0;
       }
       if(dp[idx]!=-1)
       {
        return dp[idx];
       }
       return dp[idx]=max(amount(nums,dp,idx+1),nums[idx]+amount(nums,dp,idx+2));
    }
    int rob(vector<int>& nums) {
        int n=nums.size();

        vector<int>dp(n,-1);

      return amount(nums,dp,0);
    }
};