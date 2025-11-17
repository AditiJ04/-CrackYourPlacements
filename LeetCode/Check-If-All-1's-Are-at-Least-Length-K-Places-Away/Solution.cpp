class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n=nums.size();

        int j=-1;

        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)
            {
                if(j==-1)
                {
                    j=i;
                }
                else
                {
                    if((i-j-1)<k)
                    {
                        return false;
                    }
                    j=i;
                }
            }
        }

        return true;
    }
};