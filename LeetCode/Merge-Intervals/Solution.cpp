class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        int m=intervals[0].size();

      sort(intervals.begin(), intervals.end());

        vector<vector<int>>ans;

        ans.push_back(intervals[0]);

        int prev=intervals[0][1];
        for(int i=1;i<n;i++)
        {
            if(prev>=intervals[i][0])
            {
               // ans.back()[0]=min(ans.back()[0],intervals[i][0]);
                ans.back()[1]=max(prev,intervals[i][1]);
                prev=ans.back()[1];
                continue;
            }
            ans.push_back(intervals[i]);
            prev=ans.back()[1];
        }

        return ans;
    }
};