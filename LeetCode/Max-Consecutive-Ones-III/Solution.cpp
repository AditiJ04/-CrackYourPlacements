class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int zc=0;
        int mx=0;
        int l=0,r=0;

        while(r<n)
        {
            if(nums[r]==0)
            {
                zc++;
            }

            while(zc>k)
            {
                if(nums[l]==0)
                {
                    zc--;
                }
                    l++;
                
            }
            mx=max(mx,r-l+1);
            r++;
        }

        return mx;
    }
};