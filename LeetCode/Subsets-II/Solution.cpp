1class Solution {
2public:
3    vector<vector<int>> ans;
4    map<vector<int>, int> mp;
5    void findSubsets(vector<int>& nums, int idx, vector<int> v) {
6
7        if (mp.find(v) == mp.end()) {
8            ans.push_back(v);
9        }
10
11        mp[v]++;
12        if (idx == nums.size()) {
13            return;
14        }
15        findSubsets(nums, idx + 1, v);
16        v.push_back(nums[idx]);
17        findSubsets(nums, idx + 1, v);
18    }
19    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
20        sort(nums.begin(), nums.end());
21
22        vector<int> v;
23
24        findSubsets(nums, 0, v);
25
26        return ans;
27    }
28};