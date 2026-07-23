1class Solution {
2public:
3    int climbStairs(int n) {
4
5        if (n == 0 || n == 1 || n == 2)
6            return n;
7        vector<int> dp(n + 1, 0);
8        dp[0] = 0;
9        dp[1] = 1;
10        dp[2]=2;
11
12        for (int i = 3; i <= n; i++) {
13            dp[i] = dp[i - 2] + dp[i - 1];
14        }
15
16        return dp[n];
17    }
18};
19
20//  0   1   2  3
21//  0   1   1   2