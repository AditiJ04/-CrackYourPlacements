class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        set<vector<int>>st;

        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            if(i>0 && nums[i]==nums[i-1]) continue;

            int sj=i+1;
            unordered_map<int,int>mp;
            for(int j=i+1;j<n;j++)
            {
                
                 int sum=nums[i]+nums[j];
                 int diff=0-sum;

                 if(mp.find(diff)!=mp.end())
                 {
                    st.insert({nums[i],diff,nums[j]});
                 }
                 mp[nums[j]]++;
            }
        }

        return vector<vector<int>>(st.begin(),st.end());
    }
};