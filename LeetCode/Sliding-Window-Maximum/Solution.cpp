1class Solution {
2public:
3    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
4        int n=nums.size();
5        vector<int>ans;
6        if(n==0) return {};
7
8        deque<int>dq;
9
10        for(int i=0;i<n;i++)
11        {
12            while(!dq.empty() && dq.front()<=i-k) dq.pop_front();
13            while(!dq.empty() && nums[i]>nums[dq.back()]) dq.pop_back();
14
15            dq.push_back(i);
16            if(i>=k-1)
17            {
18                ans.push_back(nums[dq.front()]);
19            }
20        }
21
22        return ans;
23    }
24};