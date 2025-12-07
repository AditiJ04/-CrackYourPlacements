1class Solution {
2public:
3    int firstMissingPositive(vector<int>& nums) {
4       int n=nums.size();
5
6       int mx=0;
7
8       unordered_map<int,int>mp;
9       for(int i=0;i<n;i++)
10       {
11        mp[nums[i]]++;
12       } 
13
14       for(int i=0;i<n;i++)
15       {
16        if(nums[i]>mx)
17        {
18            mx=nums[i];
19        }
20       }
21
22       for(int i=1;i<=mx;i++)
23       {
24        if(mp.find(i)==mp.end())
25        {
26            return i;
27        }
28       }
29       return mx+1;
30    }
31};