class Solution {
public:
    int t[101];
    int Rob(vector<int>&nums,int idx)
    {
    if(idx>=nums.size())
    {
        return 0;
    }

    if(t[idx]!=-1)
    {
        return t[idx];
    }
       int take=nums[idx]+Rob(nums,idx+2);
       int ntake=Rob(nums,idx+1);

       return t[idx]=max(take,ntake);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        memset(t,-1,sizeof(t));

        return Rob(nums,0);
    }
};