1class Solution {
2public:
3    
4    int SubArray(vector<int>&nums,int k)
5    {
6        int n=nums.size();
7        unordered_map<int,int>mp;
8
9        int i=0,j=0;
10        int ans=0;
11
12        while(i<n)
13        {
14            mp[nums[i]]++;
15            while(mp.size()>k)
16            {
17                mp[nums[j]]--;
18
19                if(mp[nums[j]]==0) mp.erase(nums[j]);
20                j++;
21            }
22
23            if(mp.size()<=k)
24            {
25                ans+=i-j+1;
26            }
27            i++;
28        }
29
30        return ans;
31    }
32    int subarraysWithKDistinct(vector<int>& nums, int k) {
33        return SubArray(nums,k)-SubArray(nums,k-1);
34    }
35};