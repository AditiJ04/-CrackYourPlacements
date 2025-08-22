class Solution {
public:
    
    int calc(vector<int>&nums,int mid)
    {
        int n=nums.size();
        int ans=0;

        for(int i=0;i<n;i++)
        {
            ans+=(nums[i]+mid-1)/mid;
        }
        return ans;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();

        int l=1;
        int h=*max_element(nums.begin(),nums.end());
        int fans=0;

        while(l<=h)
        {
            int mid=(l+h)/2;

            int val=calc(nums,mid);

            if(val<=threshold)
            {
                fans=mid;
                h=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }

        return fans;
    }
};