class Solution {
public:
    int t[101];
    int Rob(vector<int>&nums,int idx)
    {
        int take;
        int ntake;
        int n=nums.size();
        if(idx<0)
        {
            return 0;
        }

        if(t[idx]!=-1)
        {
            return t[idx];
        }
        take=nums[idx]+Rob(nums,idx-2);
        ntake=Rob(nums,idx-1);

        return t[idx]=max(take,ntake);
    }
    int rob(vector<int>& nums) {

        memset(t,-1,sizeof(t));
        int n=nums.size();
        int mxamt=INT_MIN;
        for(int i=n-1;i>=0;i--)
        {
            mxamt=max(mxamt,Rob(nums,i));
        }

        return mxamt;
    }
};