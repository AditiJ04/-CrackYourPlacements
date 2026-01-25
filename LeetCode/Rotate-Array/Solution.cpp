1class Solution {
2public:
3    void rotate(vector<int>& nums, int k) {
4    
5        int n=nums.size();
6        vector<int>v(n);
7
8        for(int i=0;i<n;i++)
9        {
10            int idx=(i+k)%n;
11            v[idx]=nums[i];
12        }
13
14        nums=v;
15    }
16};