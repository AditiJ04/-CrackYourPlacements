class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();

        int i=0;
        int j=i+1;
        int x=1;
        while(j<n)
        {
            if(nums[i]!=nums[j])
            {
                nums[x]=nums[j];
                x++;
                i++;
            }
            j++;
        }
        return i+1;
    }
};