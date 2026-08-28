1class Solution {
2public:
3    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower,
4                                               int upper) {
5        int n = nums.size();
6
7        vector<vector<int>> ans;
8        unordered_map<int, int> mp;
9
10        for (int i = 0; i < n; i++) {
11            mp[nums[i]]++;
12        }
13
14        vector<int> v;
15        for (int l = lower; l <= upper; l++) {
16            if (mp.find(l) == mp.end()) {
17                if (v.empty())
18                    v.push_back(l);
19                else if (l == upper)
20                    v.push_back(l);
21            } else {
22                if (!v.empty()) {
23                    v.push_back(l - 1);
24                    ans.push_back(v);
25                    v.clear();
26                }
27            }
28        }
29
30        if (!v.empty()) {
31
32            if(v.size()==1) v.push_back(v[0]);
33            ans.push_back(v);
34        }
35        return ans;
36    }
37};