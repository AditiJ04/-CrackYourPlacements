1class Solution {
2public:
3    int sub(vector<int>&nums,int k)
4    {
5        int n=nums.size();
6
7        unordered_map<int,int>mp;
8
9        int i=0,j=0;
10        int cnt=0;
11        while(j<n)
12        {
13            mp[nums[j]]++;
14            while(mp.size()>k)
15            {
16                mp[nums[i]]--;
17                if(mp[nums[i]]==0)
18                {
19                    mp.erase(nums[i]);
20                }
21                i++;
22            }
23            cnt+=j-i+1;
24            j++;
25        }
26        return cnt;
27    }
28    int subarraysWithKDistinct(vector<int>& nums, int k) {
29        return sub(nums,k)-sub(nums,k-1);
30    }
31};