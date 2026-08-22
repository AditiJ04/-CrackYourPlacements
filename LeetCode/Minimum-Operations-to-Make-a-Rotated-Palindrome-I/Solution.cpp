1class Solution {
2public:
3    int minOperations(string s) {
4        string str = s;
5        int mn = INT_MAX;
6        int n = s.size();
7        int cnt=0;
8
9        while (true) {
10            int i = 0, j = n - 1;
11            int ans = 0;
12
13            while (i <= j) {
14                int diff = abs(str[i] - str[j]);
15                int d = min(diff, 26 - diff);
16
17                ans += d;
18
19                i++;
20                j--;
21            }
22
23            mn=min(mn,ans+cnt);
24            rotate(str.begin(), str.begin() + 1, str.end());
25            cnt++;
26
27            if (str == s)
28                break;
29        }
30
31        return mn;
32    }
33};
34
35// uhj
36// hju
37// juh+