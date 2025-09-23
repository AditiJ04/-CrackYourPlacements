class Solution {
public:
    int row[4]={0,-1,0,1};
    int col[4]={-1,0,1,0};
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        int fresh_cnt=0;
        queue<pair<int,int>>que;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1) fresh_cnt++;
                else if(grid[i][j]==2) que.push({i,j});
            }
        }

        int mntime=0;
        while(!que.empty())
        {
            int sz=que.size();

            while(sz--)
            {
                int r=que.front().first;
                int c=que.front().second;

                int nr,nc;

                for(int j=0;j<4;j++)
                {
                    nr=r+row[j];
                    nc=c+col[j];

                    if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1)
                    {
                        grid[nr][nc]=2;
                        fresh_cnt--;
                        if(fresh_cnt==0) return mntime+1;
                        que.push({nr,nc});
                    }
                }
                que.pop();
            }
            if(!que.empty()) mntime++;
        }

       return fresh_cnt==0?mntime:-1;
    }
};