class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>>res;
        int m=matrix.size();
        int n=matrix[0].size();

        vector<int>v;
        for(int i=0;i<n;i++)
        {
           // vector<int>v;
            for(int j=0;j<m;j++)
            {
                
                v.push_back(matrix[j][i]);
            }
            res.push_back(v);
            v.clear();
        }

        return res;
    }
};