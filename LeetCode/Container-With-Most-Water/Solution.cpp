1class Solution {
2public:
3    int maxArea(vector<int>& height) {
4        int n=height.size();
5
6        int l=0,h=n-1;
7        int mx=INT_MIN;
8        
9        while(l<=h)
10        {
11            int k=min(height[l],height[h]);
12            mx=max(mx,k*(h-l));
13
14            if(height[l]>=height[h])
15            {
16                h--;
17            }
18            else
19            {
20                l++;
21            }
22        }
23
24        return mx;
25    }
26};