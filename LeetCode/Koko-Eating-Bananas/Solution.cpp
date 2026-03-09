1class Solution {
2public:
3    long long findHours(vector<int>& piles, int cap) {
4        long long cnt = 0;
5
6        for (int i = 0; i < piles.size(); i++) {
7            cnt += piles[i] / cap;
8
9            if (piles[i] % cap != 0) {
10                cnt++;
11            }
12        }
13
14        return cnt;
15    }
16    int minEatingSpeed(vector<int>& piles, int h) {
17        int n = piles.size();
18        int mx = *max_element(piles.begin(), piles.end());
19
20        int s = 1, e = mx;
21        int ans;
22        
23        while (s <= e) {
24            int mid=(s+e)/2;
25            long long hr = findHours(piles, mid);
26            if(hr<=h)
27            {
28                ans=mid;
29                e=mid-1;
30            }
31            else if(hr>h)
32            {
33                s=mid+1;
34            }
35        }
36
37        return ans;
38    }
39};