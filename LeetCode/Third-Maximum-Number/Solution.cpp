class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n=nums.size();

        long long mx1=LLONG_MIN;
        long long mx2=LLONG_MIN;
        long long mx3=LLONG_MIN;

        for(int i=0;i<n;i++)
        {
            if(nums[i]>mx1)
            {
                mx3=mx2;
                mx2=mx1;
                mx1=nums[i];
            }
            else if(nums[i]>mx2 && nums[i]!=mx1)
            {
                mx3=mx2;
                mx2=nums[i];
            }
            else if(nums[i]>mx3 && nums[i]!=mx2 && nums[i]!=mx1)
            {
                mx3=nums[i];
            }
        }

        return mx3==LLONG_MIN?mx1:mx3;
    }
};