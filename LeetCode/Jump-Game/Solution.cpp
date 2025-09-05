class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();

        if(n==1) return true;
        int mxreach=0;

        for(int i=0;i<n;i++)
        {
           mxreach=max(mxreach,nums[i]+i);

           if(i==mxreach && i!=n-1) return false;
        }

        if(mxreach>=n-1) return true;
        return false;

    }
};

