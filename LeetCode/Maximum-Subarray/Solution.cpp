1class Solution {
2public:
3    int maxSubArray(vector<int>& nums) {
4        int n=nums.size();
5
6        int mxsum=INT_MIN;
7        int sum=0;
8        int i=0;
9
10        while(i<n)
11        {
12            sum+=nums[i];
13            mxsum=max(mxsum,sum);
14            if(sum<0)
15            {
16                sum=0;
17            }
18            i++;
19        }
20
21        return mxsum;
22    }
23};