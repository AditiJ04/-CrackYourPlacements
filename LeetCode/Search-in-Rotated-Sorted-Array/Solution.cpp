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
12            if(nums[mid]==target) return mid;
13            if(nums[mid]>=nums[l])
14            {
15                if(target>=nums[l] && target<nums[mid])
16                {
17                    h=mid-1;
18                }
19                else
20                {
21                    l=mid+1;
22                }
23            }
24            else{
25                if(target>nums[mid] && target<=nums[h])
26                {
27                    l=mid+1;
28                }
29                else
30                {
31                    h=mid-1;
32                }
33            }
34        }
35
36        return -1;
37    }
38};