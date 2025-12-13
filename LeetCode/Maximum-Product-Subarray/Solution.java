1class Solution {
2public:
3    int maxProduct(vector<int>& nums) {
4        int n=nums.size();
5        int mx=INT_MIN;
6
7        int pre=1;
8        int suff=1;
9
10        for(int i=0;i<n;i++)
11        {
12            if(pre==0) pre=1;
13            if(suff==0) suff=1;
14
15            pre*=nums[i];
16            suff*=nums[n-i-1];
17
18            mx=max({mx,pre,suff});
19        }
20
21        return mx;
22    }
23};