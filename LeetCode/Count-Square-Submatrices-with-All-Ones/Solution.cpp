class Solution {
public:
    bool Check(vector<vector<int>>&matrix,int sr,int sc,int er,int ec)
    {
        int n=matrix.size();
        int m=matrix[0].size();

        for(int i=sr;i<=er;i++)
        {
            for(int j=sc;j<=ec;j++)
            {
                if(matrix[i][j]==0) return false;
            }
        }
        return true;
    }
    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

        int cnt=0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==1)
                {
                    cnt++;

                    int nr=i+1,nc=j+1;
                    
                    while(nr<n && nc<m)
                    {
                        if(Check(matrix,i,j,nr,nc)) cnt++;
                        nr++;
                        nc++;
                    }
                }
            }
        }

        return cnt;
    }
};