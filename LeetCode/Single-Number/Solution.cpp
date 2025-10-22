class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        int xor_val=0;

        for(int i=0;i<n;i++)
        {
            xor_val^=nums[i];
        }

        return xor_val;
    }
};