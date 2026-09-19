1class Solution {
2public:
3    int maxProfit(vector<int>& prices) {
4        int n=prices.size();
5        int mxPro=0;
6
7        int i=0,j=1;
8
9        while(j<n)
10        {
11            if(prices[i]>prices[j])
12            {
13                i=j;
14            }
15            mxPro=max(mxPro,prices[j]-prices[i]);
16            j++;
17        }
18
19        return mxPro;
20    }
21};