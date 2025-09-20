class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();


        int _xor=0;

        for(int i=1;i<=n;i++)
        {
            _xor=(_xor^i)^nums[i-1];
        }

        return _xor;
    }
};