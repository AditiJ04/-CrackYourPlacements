class Solution {
public:
    int row[4]={0,-1,0,1};
    int col[4]={-1,0,1,0};
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        int cntfresh=0;
        queue<pair<int,int>>que;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1) cntfresh++;
                else if(grid[i][j]==2)
                {
                    que.push({i,j});
                }
            }
        }

        if(cntfresh==0) return 0;
        int mntime=0;

        while(!que.empty())
        {
            int sz=que.size();

            for(int l=0;l<sz;l++)
            {
            auto [r,c]=que.front();
        
            for(int k=0;k<4;k++)
            {
                int nr=r+row[k];
                int nc=c+col[k];

                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1)
                {
                    grid[nr][nc]=2;
                    cntfresh--;
                    que.push({nr,nc});
                }
            }
            que.pop();
        }
            if(!que.empty()) mntime++;
        }

        return cntfresh==0?mntime:-1;
    }
};