1class Solution {
2public:
3    int countBinarySubstrings(string s) {
4        int n = s.size();
5
6        vector<pair<int, int>> v;
7        int si = 0;
8        int c = 1, ans = 0;
9
10        for (int i = 1; i < n; i++) {
11            if (s[i] == s[i - 1])
12                c++;
13            else {
14                v.push_back({si, c});
15                si = 0;
16                c = 1;
17            }
18        }
19
20        v.push_back({si, c});
21        for (int i = 1; i < v.size(); i++) {
22            ans += min(v[i].second, v[i - 1].second);
23        }
24
25        return ans;
26    }
27};