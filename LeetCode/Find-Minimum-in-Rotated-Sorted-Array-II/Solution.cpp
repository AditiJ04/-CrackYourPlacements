1class Solution {
2public:
3    int findMin(vector<int>& nums) {
4        int n = nums.size();
5
6        int l = 0, h = n - 1;
7
8        while (l < h) {
9            int mid = (l + h) / 2;
10
11            if (nums[l] >= nums[h])
12                l++;
13            else if (nums[l] <= nums[mid] && nums[mid] <= nums[h]) {
14                return nums[l];
15            }
16            else if (nums[mid] > nums[l]) {
17                l = mid + 1;
18            } else {
19                h = mid;
20            }
21        }
22
23        return nums[l];
24    }
25};
26
27// arr[mid]>arr[l]