class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int ans=0;

        unordered_map<int,int>mp;

        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }

        for(auto it:mp)
        {
            if(it.second>ceil(n/2))
            {
                ans=it.first;
                break;
            }
        }

        return ans;
    }
};