class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int>t(101,-1);

        int n=nums.size();

        if(n==1)
        {
            return nums[0];
        }

       t[0]=0;
       t[1]=nums[0];

       for(int i=2;i<=n;i++)
       {
        int take=nums[i-1]+t[i-2];
        int ntake=t[i-1];

        t[i]=max(take,ntake);
       }

       return t[n];
    }
};