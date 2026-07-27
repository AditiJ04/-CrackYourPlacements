1class Solution {
2public:
3    int minPathSum(vector<vector<int>>& grid) {
4        int n=grid.size();
5        int m=grid[0].size();
6
7        for(int i=0;i<n;i++)
8        {
9            for(int j=0;j<m;j++)
10            {
11                if(i==0 && j==0)continue;
12
13                else if(i==0)
14                {
15                    grid[i][j]+=grid[i][j-1];
16                }
17                else if(j==0)
18                {
19                    grid[i][j]+=grid[i-1][j];
20                }
21                else
22                {
23                    grid[i][j]+=min(grid[i-1][j],grid[i][j-1]);
24                }
25            }
26        }
27
28        return grid[n-1][m-1];
29    }
30};