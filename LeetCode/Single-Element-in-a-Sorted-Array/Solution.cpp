class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int xorval=0;

        for(int i=0;i<n;i++)
        {
            xorval^=nums[i];
        }

        return xorval;
    }
};