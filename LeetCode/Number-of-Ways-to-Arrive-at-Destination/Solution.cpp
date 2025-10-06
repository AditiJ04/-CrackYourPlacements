class Solution {
public:

    int mod=1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n);

        int m=roads.size();
      
        vector<long long>dist(n,LLONG_MAX);
        vector<long long>ways(n,0);

        for(int i=0;i<m;i++)
        {
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }

        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<>>pq;

        dist[0]=0;
        ways[0]=1;

        pq.push({0,0});

        while(!pq.empty())
        {
            long long d=pq.top().first;
            int node=pq.top().second;
            pq.pop();

            if(d>dist[node]) continue;    
            for(auto it:adj[node])
            {
                long long ndist=d+it.second;

                if(ndist<dist[it.first])
                {
                    dist[it.first]=ndist;
                    ways[it.first]=ways[node];
                    pq.push({ndist,it.first});
                }
                else if(ndist==dist[it.first])
                {
                    ways[it.first]=(ways[it.first]+ways[node])%mod;
                }

            }
        }

        return ways[n-1]%mod;
    }
};