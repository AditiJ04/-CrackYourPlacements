class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

        unordered_map<int,int>mp;
        int n=nums.size();
        int sum=0;

        int cnt=0;
        mp[0]++;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];

            int rem=sum%k;

            if(rem<0)
            {
                rem=k+rem;
            }
            if(mp[rem]>0)
            {
            cnt+=mp[rem];
            }
            mp[rem]++;
        }
        return cnt;
    }
};