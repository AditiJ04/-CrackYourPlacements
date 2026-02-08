1class Solution {
2public:
3    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
4        int n=nums.size();
5        int i=0,j=0;
6        int ans=0;
7        int pro=1;
8
9        while(i<n)
10        {
11            pro*=nums[i];
12
13            while(j<=i && pro>=k)
14            {
15                pro/=nums[j];
16                j++;
17            }
18            ans+=i-j+1;
19            i++;
20        }
21
22        return ans;
23    }
24};