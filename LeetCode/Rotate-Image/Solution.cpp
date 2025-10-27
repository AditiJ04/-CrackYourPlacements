class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<m;j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        for(int i=0;i<n;i++)
        {
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};

// [[3,2,1],
//  [6,5,4],
//  [9,8,7]]