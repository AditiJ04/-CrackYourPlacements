1class Solution {
2public:
3    int repeatedNTimes(vector<int>& nums) {
4        int n=nums.size()/2;
5
6        unordered_map<int,int>mp;
7        int ans=0;
8
9        for(int i=0;i<nums.size();i++)
10        {
11            mp[nums[i]]++;
12        }
13
14        for(auto it:mp)
15        {
16            if(it.second==n) {
17                ans=it.first;
18                break;
19            }
20        }
21
22        return ans;
23    }
24};