class Solution {
public:
    int row[4]={0,-1,0,1};
    int col[4]={-1,0,1,0};
    void dfs(int i,int j,vector<vector<int>>&grid,int &cnt,int id)
    {
        int n=grid.size();
        grid[i][j]=id;

        for(int k=0;k<4;k++)
        {
            int nr=i+row[k];
            int nc=j+col[k];

            if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==1)
            {
                cnt++;
                dfs(nr,nc,grid,cnt,id);
            }
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int mxl=0;
        int id=2;

        unordered_map<int,int>mp;//id-->size of island

        vector<vector<int>>vis(n,vector<int>(n,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int cnt=1;
                if(grid[i][j]==1)
                {
                    dfs(i,j,grid,cnt,id);
                    mxl=max(mxl,cnt);
                    mp[id]=cnt;
                    id++;
                }
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0)
                {
                    unordered_set<int>uq;
                  /*  int cnt=1;
                    grid[i][j]=1;

                    vector<vector<int>>vis(n,vector<int>(n,0));
                    dfs(i,j,grid,vis,cnt);
                    mxl=max(mxl,cnt);
                    mp[id]=cnt;
                    grid[i][j]=0;*/

                    for(int k=0;k<4;k++)
                    {
                        int nr=i+row[k];
                        int nc=j+col[k];

                        if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]!=0)
                        {
                            uq.insert(grid[nr][nc]);
                        }
                    }

                    int overallsize=1;
                    for(auto &it:uq)
                    {
                        overallsize+=mp[it];
                    }

                    mxl=max(mxl,overallsize);
                }
                
            }
        }

        return mxl==0?n*n:mxl;
    }
};