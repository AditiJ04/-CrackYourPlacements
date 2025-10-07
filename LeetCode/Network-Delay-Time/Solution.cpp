class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);

        int m=times.size();

        for(int i=0;i<m;i++)
        {
            adj[times[i][0]].push_back({times[i][2],times[i][1]});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>que;

        que.push({0,k});

        vector<int>dist(n+1,INT_MAX);

        dist[0]=0;
        dist[k]=0;

        while(!que.empty())
        {
            auto ele=que.top();
            int dis=ele.first;
            int node=ele.second;

            que.pop();
            for(auto it:adj[node])
            {
                int d=it.first;
                int v=it.second;

                if(dis+d<dist[v])
                {
                    dist[v]=dis+d;
                    que.push({dis+d,v});
                }
            }
        }

        int mx=INT_MIN;
        for(int i=1;i<=n;i++)
        {
            if(dist[i]==INT_MAX)
            {
                return -1;
            }
            mx=max(mx,dist[i]);
        }

        return mx;
    }
};