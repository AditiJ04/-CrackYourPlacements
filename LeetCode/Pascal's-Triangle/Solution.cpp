class Solution {
public:
    vector<int>Generaterow(int row)
    {
        long long ans=1;
        vector<int>ansR;
        ansR.push_back(1);

        for(int col=1;col<row;col++)
        {
            ans=ans*(row-col);
            ans=ans/col;
            ansR.push_back(ans);
        }

        return ansR;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>res;

        for(int i=1;i<=numRows;i++)
        {
            res.push_back(Generaterow(i));
        }

        return res;
    }
};