1class Solution {
2public:
3    int findPeakElement(vector<int>& nums) {
4        int n=nums.size();
5
6        if(n==1) return 0;
7
8        if(nums[0]>nums[1]) return 0;
9        if(nums[n-2]<nums[n-1]) return n-1;
10
11        int l=1,h=n-2;
12
13        while(l<=h)
14        {
15            int mid=(l+h)/2;
16
17            if(nums[mid-1]<nums[mid] && nums[mid]>nums[mid+1])
18            {
19                return mid;
20            }
21            else if(nums[mid]<nums[mid+1]) l=mid+1;
22            else
23            {
24                h=mid-1;
25            }
26        }
27
28        return l;
29    }
30};
31
32// 1 2 3 1
33// 0 1 2 3
34