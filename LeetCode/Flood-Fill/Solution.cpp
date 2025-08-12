class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();

        int row[]={0,-1,0,+1};
        int col[]={-1,0,+1,0};

        vector<vector<int>>ans=image;

        vector<vector<int>>vis(n,vector<int>(m,0));

        queue<pair<int,int>>que;

        que.push({sr,sc});

        vis[sr][sc]=1;
        ans[sr][sc]=color;

        while(!que.empty())
        {
            int s=que.size();

            while(s--)
            {
            int r=que.front().first;
            int c=que.front().second;

            que.pop();
            for(int i=0;i<4;i++)
            {
                int nr=r+row[i];
                int nc=c+col[i];

                if(nr>=0 && nr<n && nc>=0 && nc<m && ans[nr][nc]==image[sr][sc] && !vis[nr][nc])
                {
                    ans[nr][nc]=color;
                    vis[nr][nc]=1;

                    que.push({nr,nc});
                }
            }

            }
        }

        return ans;
    }
};