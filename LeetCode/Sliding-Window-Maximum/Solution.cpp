1class Solution {
2public:
3    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
4        int n = nums.size();
5
6        priority_queue<pair<int, int>> pq;
7        vector<int> ans;
8        for (int i = 0; i < n; i++) {
9            pq.push({nums[i], i});
10            while (pq.size() > k) {
11                int idx = pq.top().second;
12                if (idx <= i - k)
13                    pq.pop();
14                else
15                    break;
16            }
17            if (pq.size() >= k) {
18                ans.push_back(pq.top().first);
19            }
20        }
21
22        return ans;
23    }
24};