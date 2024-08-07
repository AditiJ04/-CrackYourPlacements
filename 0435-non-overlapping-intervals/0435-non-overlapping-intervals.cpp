class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b)
    {
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();

        sort(intervals.begin(),intervals.end(),cmp);

        vector<vector<int>>ans;
        int i=0;
        int cnt=0;

        for(int i=0;i<n;i++)
        {
            if(ans.empty() || intervals[i][0]>=ans.back()[1])
            {
                ans.push_back(intervals[i]);
            }
            else
            {
                cnt++;
            }
        }

        return cnt;
    }
};