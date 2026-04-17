1class Solution {
2public:
3    int findRev(int dig) {
4        int num = 0;
5
6        while (dig != 0) {
7            int r = dig % 10;
8            num = num * 10 + r;
9            dig /= 10;
10        }
11
12        return num;
13    }
14    int minMirrorPairDistance(vector<int>& nums) {
15        int n = nums.size();
16        int mn=INT_MAX;
17
18        unordered_map<int, int> mp;
19
20        for (int i=0;i<n;i++)
21        {
22            int dig=findRev(nums[i]);
23
24            if(mp.find(nums[i])!=mp.end())
25            {
26                if(i>mp[nums[i]])
27                {
28                    mn=min(mn,i-mp[nums[i]]);
29                }
30            }
31            mp[dig]=i;
32        }
33
34        return mn==INT_MAX?-1:mn;
35    }
36};