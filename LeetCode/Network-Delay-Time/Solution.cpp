class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int m=times.size();

        vector<vector<pair<int,int>>>adj(n+1);

        for(int i=0;i<m;i++)
        {
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }

        vector<int>dist(n+1,INT_MAX);

        dist[k]=0;

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;

        pq.push({0,k});

        while(!pq.empty())
        {
            int dis=pq.top().first;
            int node=pq.top().second;
            pq.pop();

            if(dis>dist[node]) continue;

            for(auto it:adj[node])
            {
                if(dis+it.second<dist[it.first])
                {
                    dist[it.first]=dis+it.second;
                    pq.push({dis+it.second,it.first});
                }
            }
        }

        int mx=INT_MIN;

        for(int i=1;i<=n;i++)
        {
            if(dist[i]==INT_MAX) return -1;
            mx=max(mx,dist[i]);
        }

        return mx;
    }
};