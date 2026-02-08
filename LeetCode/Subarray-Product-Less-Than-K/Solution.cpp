1class Solution {
2public:
3    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
4        int cnt=0;
5        for(int i=0;i<nums.size();i++)
6        {
7            int pro=nums[i];
8            if(pro<k)
9            {
10                cnt++;
11            }
12            for(int j=i+1;j<nums.size();j++)
13            {
14                pro*=nums[j];
15                if(pro<k)
16                {
17                    cnt++;
18                }
19                else
20                {
21                    break;
22                }
23            }
24        }
25        return cnt;
26    }
27};