1class Solution {
2public:
3    int singleNonDuplicate(vector<int>& nums) {
4        int n=nums.size();
5        int xorval=0;
6
7        for(int i=0;i<n;i++)
8        {
9            xorval^=nums[i];
10        }
11
12        return xorval;
13    }
14};