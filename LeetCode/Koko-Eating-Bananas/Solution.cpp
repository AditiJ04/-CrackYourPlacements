1class Solution {
2public:
3     long long findEatingSpeed(vector<int>&piles,int capacity)
4    {
5        long long cnt=0;
6
7        for(int i=0;i<piles.size();i++)
8        {
9            cnt+=(piles[i]%capacity==0)?(piles[i]/capacity):(piles[i]/capacity)+1;
10        }
11        return cnt;
12    }
13    int minEatingSpeed(vector<int>& piles, int h) {
14        int n=piles.size();
15
16        int l=1;
17        int r=*max_element(piles.begin(),piles.end());
18
19        int ans=0;
20        while(l<=r)
21        {
22            int mid=(l+r)/2;
23            long long cnt=findEatingSpeed(piles,mid);
24
25            if(cnt<=h)
26            {
27                ans=mid;
28                r=mid-1;
29            }
30            else
31            {
32                l=mid+1;
33            }
34        }
35
36        return ans;
37    }
38};