class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int mxreach=0;
        int curr=0;
    
        for(int i=0;i<n;i++)
        {
            mxreach=max(mxreach,nums[i]+i);

            if(mxreach==i) break;
        }

        if(mxreach>=n-1) return true;
        return false;
    }
};