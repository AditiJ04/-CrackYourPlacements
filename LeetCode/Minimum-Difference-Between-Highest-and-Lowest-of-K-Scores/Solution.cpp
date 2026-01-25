1class Solution {
2public:
3    int minimumDifference(vector<int>& nums, int k) {
4
5        int n=nums.size();
6        sort(nums.begin(),nums.end());
7
8        int ans=INT_MAX;
9        for(int i=0;i<=n-k;i++)
10        {
11            int mn=nums[i];
12            int mx=nums[i+k-1];
13
14            ans=min(ans,mx-mn);
15        }
16
17        return ans;
18    }
19};
20
21// 5 4 7 8