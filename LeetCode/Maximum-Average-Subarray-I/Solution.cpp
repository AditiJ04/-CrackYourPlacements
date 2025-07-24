class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i=0,j=0;
        int n=nums.size();

        int mx=INT_MIN;
        int avg=0;
        int sum=0;

        while(j<n)
        {
            sum+=nums[j];
            if(j-i+1<k)
            {
                j++;
            }

            else if(j-i+1==k)
            {
            mx=max(mx,sum);
            sum-=nums[i];
            i++;
            j++;
            }
        }

        return mx/(double)k;
    }
};