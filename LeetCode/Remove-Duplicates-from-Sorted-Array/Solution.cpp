class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int j=0,i;
        int cnt=1;
        for(i=1;i<n;i++)
        {
            if(nums[i]==nums[j])
            {
                continue;
            }
            else
            {
                j++;
                nums[j]=nums[i];
                cnt++;
            }
        }
        return cnt;
    }
};