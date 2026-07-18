1class Solution {
2public:
3
4    set<vector<int>>ans;
5
6    void Subset(vector<int>&nums,vector<int>&v,int idx)
7    {
8
9       // sort(v.begin(),v.end());
10        ans.insert(v);
11
12        if(idx==nums.size())
13        {
14            return;
15        }
16
17        for(int i=idx;i<nums.size();i++)
18        {
19
20         /*  if (i > idx && nums[i] == nums[i - 1]) {
21            continue;
22        }*/
23            v.push_back(nums[i]);
24            Subset(nums,v,i+1);
25            v.pop_back();
26        }
27    }
28    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
29        int n=nums.size();
30
31        vector<int>v;
32
33        sort(nums.begin(),nums.end());
34
35        Subset(nums,v,0);
36
37        vector<vector<int>>res;
38
39        for(auto it:ans)
40        {
41            res.push_back(it);
42        }
43
44        return res;
45    }
46};