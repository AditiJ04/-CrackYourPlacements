1class Solution {
2public:
3    int maxScore(vector<int>& cardPoints, int k) {
4        int n=cardPoints.size();
5        int wl=n-k;
6        int tsum=accumulate(cardPoints.begin(),cardPoints.end(),0);
7
8        if(n==k) return tsum;
9
10        int ans=0;
11
12        int i=0,j=0;
13        int sum=0;
14
15        while(j<n)
16        {
17            sum+=cardPoints[j];
18            if(j-i+1==wl)
19            {
20                ans=max(ans,tsum-sum);
21                sum-=cardPoints[i];
22                i++;
23            }
24            j++;
25        }
26
27        return ans;
28    }
29};