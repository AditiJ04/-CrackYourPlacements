class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_map<int,int>mp;

        int n=nums.size();

        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }

        int ans=original;

        while(true)
        {
            if(mp.find(ans)!=mp.end())
            {
                ans=2*ans;
            }
            else
            {
                break;
            }
        }

        return ans;
    }
};