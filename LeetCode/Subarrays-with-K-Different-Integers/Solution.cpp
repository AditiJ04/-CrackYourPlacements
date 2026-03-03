1class Solution {
2public:
3    int findSubarrays(vector<int>& nums, int k) {
4        int n = nums.size();
5
6        int i = 0, j = 0;
7        unordered_map<int, int> mp;
8        int ans = 0;
9
10        while (i < n) {
11            mp[nums[i]]++;
12            while (mp.size() > k) {
13                mp[nums[j]]--;
14                if (mp[nums[j]] == 0)
15                    mp.erase(nums[j]);
16                j++;
17            }
18
19            if (mp.size() <= k) {
20                ans += i - j+1;
21            }
22            i++;
23        }
24
25        return ans;
26    }
27    int subarraysWithKDistinct(vector<int>& nums, int k) {
28        return findSubarrays(nums, k)-findSubarrays(nums,k-1);
29    }
30};