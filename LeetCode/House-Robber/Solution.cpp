class Solution {
public:
    int n,dp[101];
    int maxAmount(vector<int>&nums,int idx)
    {
        if(idx>=nums.size()) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int take=nums[idx]+maxAmount(nums,idx+2);
        int ntake=maxAmount(nums,idx+1);

        return dp[idx]=max(take,ntake);
    }
    int rob(vector<int>& nums) {
        n=nums.size();
        memset(dp,-1,sizeof(dp));
        return maxAmount(nums,0);
    }
};