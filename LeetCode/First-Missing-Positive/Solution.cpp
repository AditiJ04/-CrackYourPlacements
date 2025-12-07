1class Solution {
2public:
3    int firstMissingPositive(vector<int>& nums) {
4        int n=nums.size();
5
6        unordered_map<int,int>mp;
7        for(int i=0;i<n;i++)
8        {
9            mp[nums[i]]++;
10        }
11        int num=1;
12
13        for(auto it:mp)
14        {
15            if(mp.find(num)!=mp.end()){
16                num++;
17            }
18            else
19            {
20                break;
21            }
22        }
23
24        return num;
25    }
26};