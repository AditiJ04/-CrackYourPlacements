1class Solution {
2public:
3    vector<int> productExceptSelf(vector<int>& nums) {
4        int n=nums.size();
5        vector<int>v(n);
6
7        v[0]=1;
8
9        for(int i=1;i<n;i++)
10        {
11            v[i]=v[i-1]*nums[i-1];
12        }
13
14        // 1 2 3 4
15        // 1 1 2 6
16        //     4  1 
17        int rt=1;
18        for(int i=n-1;i>=0;i--)
19        {
20            v[i]*=rt;
21            rt*=nums[i];
22        }
23
24        return v;
25    }
26};