class Solution {
public:
    int maxAmount(vector<int>&nums,vector<int>&dp,int idx)
    {
        if(idx>=nums.size())
        {
            return 0;
        }

        if(dp[idx]!=-1)
        {
            return dp[idx];
        }

        return dp[idx]=max(nums[idx]+maxAmount(nums,dp,idx+2),maxAmount(nums,dp,idx+1));
    }
    int rob(vector<int>& nums) {
        int n=nums.size();

        vector<int>dp(n,-1);
        return maxAmount(nums,dp,0);
    }
};