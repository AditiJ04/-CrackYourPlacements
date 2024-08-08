class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        vector<vector<int>>ans;
        priority_queue<pair<int,vector<int>>,vector<pair<int,vector<int>>>,greater<pair<int,vector<int>>>>pq;

        int n=points.size();
        for(int i=0;i<n;i++)
        {
            int a=points[i][0];
            int b=points[i][1];

            int dist=a*a+b*b;

            pq.push({dist,{a,b}});
        }
        while(k!=0)
        {
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }

        return ans;
    }
};