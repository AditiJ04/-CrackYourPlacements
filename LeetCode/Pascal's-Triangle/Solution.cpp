class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;

        ans.push_back({1});
     //   ans.push_back({1,1});

        for(int i=2;i<=numRows;i++)
        {
            vector<int>v=ans.back();
            vector<int>nv;

            nv.push_back(v[0]);
            for(int i=1;i<v.size();i++)
            {
                nv.push_back(v[i]+v[i-1]);
            }
             nv.push_back(v[0]);
             ans.push_back(nv);
        }

        return ans;
    }
};