class Solution {
public:
    int mod=1e9+7;

    int numSubseq(vector<int>& nums, int target) {
        int n=nums.size();

        sort(nums.begin(),nums.end());

        vector<int>P(n);
        P[0]=1;

        for(int i=1;i<n;i++)
        {
            P[i]=(P[i-1]*2)%mod;
        }

        int l=0;
        int h=n-1;

        int res=0;

        while(l<=h)
        {
            if(nums[l]+nums[h]<=target)
            {
                res=(res%mod+P[h-l])%mod;
                l++;
            }
            else
            {
                h--;
            }
        }

        return res;
    }
};