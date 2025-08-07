class Solution {
public:

    int t[101];
    int Rob(int idx,vector<int>&nums)
    {
        if(idx>=nums.size())
        {
            return 0;
        }

        if(t[idx]!=-1)
        {
            return t[idx];
        }
       int steal=nums[idx]+Rob(idx+2,nums);
       int skip=Rob(idx+1,nums);

       return t[idx]=max(steal,skip);
    }
    int rob(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        return Rob(0,nums);
    }
};