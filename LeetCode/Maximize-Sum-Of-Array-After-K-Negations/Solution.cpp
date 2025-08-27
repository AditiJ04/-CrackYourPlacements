class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int n=nums.size();


        sort(nums.begin(),nums.end());

        for(int i=0;i<n && k>0;i++)
        {
            if(nums[i]<0)
            {
                nums[i]=-nums[i];
                k--;
            }
        }

        if((k%2)!=0)
        {
            int minidx=min_element(nums.begin(),nums.end())-nums.begin();
            nums[minidx]=-nums[minidx];
        }

        return accumulate(nums.begin(),nums.end(),0);
    }
};