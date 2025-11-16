class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        int cnt=0;

        unordered_map<int,int>mp;
        mp[0]++;

        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];

            int r=(sum%k+k)%k;

            if(mp.find(r)!=mp.end())
            {
                cnt+=mp[r];
            }
            mp[r]++;
        }

        return cnt;
    }
};