1class Solution {
2public:
3
4    vector<vector<int>>ans;
5
6    void findCombination(vector<int>&nums,int k,int sum,vector<int>v,int idx)
7    {
8        if(sum==0 && k==0)
9        {
10            ans.push_back(v);
11            return;
12        }
13
14        if(idx==nums.size()) return;
15
16        findCombination(nums,k,sum,v,idx+1);
17
18        if(sum-nums[idx]>=0)
19        {
20            v.push_back(nums[idx]);
21            findCombination(nums,k-1,sum-nums[idx],v,idx+1);
22        }
23    }
24    vector<vector<int>> combinationSum3(int k, int n) {
25        vector<int>nums={1,2,3,4,5,6,7,8,9};
26
27        vector<int>v;
28        findCombination(nums,k,n,v,0);
29
30        return ans;
31    }
32};