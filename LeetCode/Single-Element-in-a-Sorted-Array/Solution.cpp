class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();

        int l=0;
        int h=n-1;

        while(l<h)
        {
            int mid=(l+h)/2;

            if(mid%2!=0)
            {
                mid--;
            }

            if(nums[mid]!=nums[mid+1])
            {
                h=mid;
            }
            else
            {
                l=mid+2;
            }
        }
        return nums[l];
    }
};