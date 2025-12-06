1class Solution {
2public:
3    int maxScore(vector<int>& cardPoints, int k) {
4        int n=cardPoints.size();
5
6        int tsum=accumulate(cardPoints.begin(),cardPoints.end(),0);
7        int mx=INT_MIN;
8        int l=n-k;
9        if(n==k) return tsum;
10        int i=0,j=0;
11        int sum=0;
12
13        while(i<n)
14        {
15            sum+=cardPoints[i];
16
17            if(i-j+1==l)
18            {
19                mx=max(mx,tsum-sum);
20                while(i-j+1==l)
21                {
22                    sum-=cardPoints[j];
23                    j++;
24                }
25            }
26            i++;
27        }
28        return mx;
29    }
30};