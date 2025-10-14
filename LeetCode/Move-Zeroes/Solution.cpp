class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();

        int x=0;

        for(int i=0;i<n;i++)
        {
            if(nums[i]!=0)
            {
                int tmp=nums[i];
                nums[i]=nums[x];
                nums[x]=tmp;
                x++;
            }
        }
    }
};