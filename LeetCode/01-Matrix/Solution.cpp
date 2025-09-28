class Solution {
public:

    int row[4]={0,-1,0,1};
    int col[4]={-1,0,1,0};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();

        vector<vector<int>>nmat(n,vector<int>(m,-1));

        queue<pair<int,int>>q;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                   nmat[i][j]=0;
                   q.push({i,j});
                }
            }
        }

        while(!q.empty())
        {
            int r=q.front().first;
            int c=q.front().second;

            for(int i=0;i<4;i++)
            {
                int nr=r+row[i];
                int nc=c+col[i];

                if(nr>=0 && nr<n && nc>=0 && nc<m && nmat[nr][nc]==-1)
                {
                    nmat[nr][nc]=1+nmat[r][c];
                    q.push({nr,nc});
                }
            }
            q.pop();
        }

        return nmat;

    }
};