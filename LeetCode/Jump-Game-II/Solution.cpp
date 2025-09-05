class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int far=0,curr=0,jmps=0;

        for(int i=0;i<n-1;i++)
        {
            far=max(far,i+nums[i]);
            if(i==curr)
            {
                jmps++;
                curr=far;
            }
        }

        return jmps;
    }
};