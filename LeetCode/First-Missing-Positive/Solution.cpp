1class Solution {
2public:
3    int firstMissingPositive(vector<int>& nums) {
4        unordered_map<int,int>mp;
5        int mx=0;
6        for(int i=0;i<nums.size();i++)
7        {
8            mp[nums[i]]++;
9        }
10
11        for(int i=0;i<nums.size();i++)
12        {
13            if(nums[i]>mx)
14            {
15                mx=nums[i];
16            }
17        }
18        for(int i=1;i<=mx;i++)
19        {
20            if(mp.find(i)==mp.end())
21            {
22                return i;
23            }
24        }
25        return mx+1;
26    }
27};