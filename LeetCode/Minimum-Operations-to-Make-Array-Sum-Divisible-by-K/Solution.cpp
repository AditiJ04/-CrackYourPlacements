1class Solution {
2public:
3    int minOperations(vector<int>& nums, int k) {
4        int n=nums.size();
5        int sum=accumulate(nums.begin(),nums.end(),0);
6
7        if(k>sum) return sum;
8        if(sum%k==0) return 0;
9
10        return sum%k;
11    }
12};