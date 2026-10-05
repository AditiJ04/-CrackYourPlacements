1class Solution {
2public:
3    int findMaxArea(int i, int j, vector<vector<int>>& grid,
4                    vector<vector<int>>& vis) {
5        int n = grid.size(), m = grid[0].size();
6        if (i == n || i < 0 || j < 0 || j == m)
7            return 0;
8
9        vis[i][j] = 1;
10
11        int d1 = 0, d2 = 0, d3 = 0, d4 = 0;
12  
13        if ((i - 1) >= 0 && grid[i-1][j] && !vis[i-1][j])
14            d1 = findMaxArea(i - 1, j, grid, vis);
15        if ((j - 1) >= 0 && grid[i][j-1] && !vis[i][j-1])
16            d2 = findMaxArea(i, j - 1, grid, vis);
17        if ((i + 1) < n && grid[i+1][j] && !vis[i+1][j])
18            d3 = findMaxArea(i + 1, j, grid, vis);
19        if ((j + 1) < m && grid[i][j+1] && !vis[i][j+1])
20            d4 = findMaxArea(i, j + 1, grid, vis);
21
22        return 1 + (d1+d2+d3+d4);
23    }
24    int maxAreaOfIsland(vector<vector<int>>& grid) {
25
26        int n = grid.size(), m = grid[0].size();
27        int mx = 0;
28
29        vector<vector<int>> vis(n, vector<int>(m, 0));
30        for (int i = 0; i < n; i++) {
31            for (int j = 0; j < m; j++) {
32                if (!vis[i][j] && grid[i][j] == 1) {
33                    mx = max(mx, findMaxArea(i, j, grid, vis));
34                }
35            }
36        }
37
38        return mx;
39    }
40};