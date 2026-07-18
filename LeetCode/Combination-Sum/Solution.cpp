1class Solution {
2public:
3
4    vector<vector<int>>ans;
5
6    void findSum(vector<int>&candidates,int target,int idx,vector<int>&v)
7    {
8        if(idx==candidates.size()) return;
9
10        if(target==0)
11        {
12            ans.push_back(v);
13            return;
14        }
15        if(target-candidates[idx]>=0)
16        {
17            v.push_back(candidates[idx]);
18            findSum(candidates,target-candidates[idx],idx,v);
19            v.pop_back();
20        }
21
22        findSum(candidates,target,idx+1,v);
23    }
24    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
25        int n=candidates.size();
26
27        vector<int>v;
28        findSum(candidates,target,0,v);
29
30        return ans;
31    }
32};