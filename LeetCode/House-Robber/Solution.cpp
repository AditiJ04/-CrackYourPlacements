class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int prev=0;
        int curr=nums[0];

        for(int i=1;i<n;i++)
        {
            int prev1=curr;
            curr=max(curr,nums[i]+prev);
            prev=prev1;
        }

        return curr;
    }
};