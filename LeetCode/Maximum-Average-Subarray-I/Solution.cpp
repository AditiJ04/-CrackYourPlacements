class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0,j=0;

        double sum=0;
        double mx=-DBL_MAX;

        while(j<n)
        {
            sum+=nums[j];
            if(j-i+1==k)
            {
                mx=max(mx,sum/k);
                sum-=nums[i];
                i++;
            }
            j++;
        }

        return mx;
    }
};