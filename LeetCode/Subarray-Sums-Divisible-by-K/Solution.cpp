class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();

        vector<long long>pre(n,0);
        pre[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            pre[i]=pre[i-1]+nums[i];
        }

        map<long long,int>mp;
        int cnt=0;
        mp[0]=1;
        for(int i=0;i<n;i++)
        {
             long long rem=((pre[i]%k+k)%k);
            // if (rem < 0) rem += k;

            if(mp.find(rem)!=mp.end())
            {
                cnt+=mp[rem];
            }
            mp[rem]++;
        }

        return cnt;
    }
};