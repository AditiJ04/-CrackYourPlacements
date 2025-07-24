class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();

        int l=0,r=0;
        double sum=0;

        double mx=INT_MIN;

        while(r<n)
        {
            sum+=nums[r];
            while((r-l+1)>k)
            {
                sum-=nums[l];
                l++;
            }
            if((r-l+1)==k)
            {
                mx=max(mx,sum/k);
            }
            r++;
        }

        return mx;
    }
};