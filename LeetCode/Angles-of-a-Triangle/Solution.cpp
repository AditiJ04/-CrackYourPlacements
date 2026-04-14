1class Solution {
2public:
3    vector<double> internalAngles(vector<int>& sides) {
4        if (sides[0] + sides[1] <= sides[2])
5            return {};
6        if (sides[1] + sides[2] <= sides[0])
7            return {};
8        if (sides[0] + sides[2] <= sides[1])
9            return {};
10
11        int a = sides[0], b = sides[1], c = sides[2];
12
13        double A = acos((b * b + c * c - a * a) / (2.0 * b * c));
14        double B = acos((a * a + c * c - b * b) / (2.0 * a * c));
15        double C = acos((a * a + b * b - c * c) / (2.0 * a * b));
16
17        A = A * 180 / M_PI;
18        B = B * 180 / M_PI;
19        C = C * 180 / M_PI;
20
21        vector<double> ans;
22
23        ans.push_back(A);
24        ans.push_back(B);
25        ans.push_back(C);
26
27        sort(ans.begin(), ans.end());
28
29        return ans;
30    }
31};