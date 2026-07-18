1class Solution {
2public:
3
4    vector<vector<int>>ans;
5
6    void solve(vector<int>&candidates,int target,vector<int>&v,int idx)
7    {
8        if(target==0)
9        {
10            ans.push_back(v);
11            return;
12        }
13        if(idx==candidates.size())
14        {
15            return;
16        }
17        if(candidates[idx]<=target)
18        {
19            v.push_back(candidates[idx]);
20            solve(candidates,target-candidates[idx],v,idx);
21            v.pop_back();
22        }
23        solve(candidates,target,v,idx+1);
24    }
25    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
26        int n=candidates.size();
27
28        vector<int>v;
29        solve(candidates,target,v,0);
30
31        return ans;
32    }
33};