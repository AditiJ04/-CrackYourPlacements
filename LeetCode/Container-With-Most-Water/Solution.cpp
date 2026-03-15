1class Solution {
2public:
3    int maxArea(vector<int>& height) {
4        int n=height.size();
5
6        int l=0;
7        int h=n-1;
8
9        int mx=INT_MIN;
10        while(l!=h)
11        {
12            int k=min(height[l],height[h]);
13            mx=max(mx,k*(h-l));
14
15            if(height[l]<=height[h])
16            {
17                l++;
18            }
19            else if(height[l]>=height[h])
20            {
21                h--;
22            }
23        }
24
25        return mx;
26
27    }
28};