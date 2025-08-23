class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
       int n=mat.size();
       int m=mat[0].size();

       for(int i=0;i<n;i++)
       {
        for(int j=0;j<m;j++)
        {
            int curr=mat[i][j];
            if(j>0 && mat[i][j-1]>=curr) continue;
            if(j<m-1 && mat[i][j+1]>=curr) continue;
            if(i<n-1 && mat[i+1][j]>=curr) continue;
            if(i>0 && mat[i-1][j]>=curr) continue;

            return {i,j};
        }
       }

        return {-1,-1};
    }
};