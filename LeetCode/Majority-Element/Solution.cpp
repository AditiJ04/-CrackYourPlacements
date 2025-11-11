class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int v=0;
        int can=0;

        for(int i=0;i<n;i++)
        {
            if(v==0)
            {
                v++;
                can=nums[i];
            }
            else
            {
                if(nums[i]==can)
                {
                    v++;
                }
                else
                {
                    v--;
                }
            }
        }

        int cnt=0;

        for(int i=0;i<n;i++)
        {
            if(nums[i]==can)
            {
                cnt++;
            }
        }

        if(cnt>ceil(n/2))
        {
            return can;
        }

        return -1;
    }
};