class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;

        ans.push_back({1});
        

        while(numRows>1)
        {
            vector<int>prev=ans.back();
            vector<int>curr(prev.size()+1);

            curr[0]=prev[0];
            curr[curr.size()-1]=prev[prev.size()-1];

            for(int i=1;i<curr.size()-1;i++)
            {
                curr[i]=prev[i]+prev[i-1];
            }
            ans.push_back(curr);
            numRows--;
        }

        return ans;
    }
};