class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx=INT_MIN;

        int n=nums.size();

        for(int i=0;i<n;i++)
        {
            int pro=1;

            for(int j=i;j<n;j++)
            {
                pro*=nums[j];
                mx=max(mx,pro);
            }
        }

        return mx;
    }
};