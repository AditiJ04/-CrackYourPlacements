class Solution {
public:
int mx=0;
    void dfs(vector<vector<int>>&grid,int r,int c,int &cnt)
    {
        int nr=grid.size();
        int nc=grid[0].size();
        grid[r][c]=0;
        cnt++;
        mx=max(mx,cnt);
        if(r-1>=0 && grid[r-1][c]==1) dfs(grid,r-1,c,cnt);
        if(r+1<nr && grid[r+1][c]==1) dfs(grid,r+1,c,cnt);
        if(c-1>=0 && grid[r][c-1]==1) dfs(grid,r,c-1,cnt);
        if(c+1<nc && grid[r][c+1]==1) dfs(grid,r,c+1,cnt);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    int cnt=0;
                    dfs(grid,i,j,cnt);
                }
            }
        }

        return mx;
    }
};