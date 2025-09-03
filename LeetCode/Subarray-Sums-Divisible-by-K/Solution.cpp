class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();

        unordered_map<int,int>mp;
        int cnt=0;
        mp[0]=1;

        int pre=0;

        for(int i=0;i<n;i++)
        {
            pre+=nums[i];
            int div=((pre%k+k)%k);
            if(mp.find(div)!=mp.end())
            {
                cnt+=mp[div];
            }
            mp[div]++;
        }

        return cnt;
    }
};