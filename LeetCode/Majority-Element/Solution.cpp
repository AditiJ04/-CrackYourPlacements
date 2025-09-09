class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();

        int i,candidate=-1,votes=0;

        for(int i=0;i<n;i++)
        {
            if(votes==0)
            {
                candidate=nums[i];
                votes=1;
            }
            else
            {
                if(nums[i]==candidate) votes++;
                else votes--;
            }
        }

        int cnt=0;

        for(int i=0;i<n;i++)
        {
            if(nums[i]==candidate) cnt++;
        }

        if(cnt>ceil(n/2)) return candidate;

        return -1;
    }
};