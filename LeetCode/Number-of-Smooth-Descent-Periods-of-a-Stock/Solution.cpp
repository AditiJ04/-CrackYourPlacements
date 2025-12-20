1class Solution {
2public:
3    long long getDescentPeriods(vector<int>& prices) {
4        long long ans=1;
5        int n=prices.size();
6        int idx=0;
7        for(int i=1;i<n;i++)
8        {
9            if(prices[i]+1!=prices[i-1])
10            {
11                idx=i;
12            }
13            ans+=(i-idx+1);
14        }
15        return ans;
16    }
17};