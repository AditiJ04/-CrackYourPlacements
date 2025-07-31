class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();

        int i=0,j=0;
        int sum=0;
        int mxlen=INT_MAX;
        while(i<n)
        {
            sum+=nums[i];
            if(sum==target)
            {
                mxlen=min(mxlen,i-j+1);
                sum-=nums[j];
                j++;
            }

            else
            {
            while(sum>=target)
            {
                  mxlen=min(mxlen,i-j+1);
                sum-=nums[j];
                j++;
            }

            }
            i++;
        }

        if(mxlen==INT_MAX)
        {
            return 0;
        }
        return mxlen;
    }
};