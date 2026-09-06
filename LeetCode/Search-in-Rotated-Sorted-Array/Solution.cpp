1class Solution {
2public:
3    int search(vector<int>& nums, int target) {
4        int n=nums.size();
5
6        int l=0,h=n-1;
7
8        while(l<=h)
9        {
10            int mid=(l+h)/2;
11
12            if(target==nums[mid]) return mid;
13            if(nums[l]<=nums[mid])
14            {
15                if(nums[l]<=target && target<nums[mid]) h=mid-1;
16                else l=mid+1;
17            }
18            else
19            {
20                if(nums[mid]<target && nums[h]>=target)
21                {
22                    l=mid+1;
23                }
24                else
25                {
26                    h=mid-1;
27                }
28            }
29        }
30
31        return -1;
32    }
33};
34
35
36//6 7 0 1 2 4 5
37//0 1 2 3 4 5 6