1class Solution {
2public:
3    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
4        int n=nums.size();
5
6        int i=0;
7
8        int j=0;
9        int pro=1,cnt=0;
10        if(k<=1)
11        {
12            return 0;
13        }
14        while(j<n)
15        {
16            pro*=nums[j];
17
18            while(pro>=k)
19            {
20                pro/=nums[i];
21                i++;
22            }
23            cnt+=j-i+1;
24            j++;
25        }
26        return cnt;
27    }
28};