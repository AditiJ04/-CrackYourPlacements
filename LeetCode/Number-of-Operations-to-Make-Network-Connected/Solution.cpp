class Solution {
public:

    void dfs(vector<vector<int>>&adj,vector<int>&vis,int node)
    {
        if(vis[node]) return;
        vis[node]=1;
        for(auto it:adj[node])
        {
            dfs(adj,vis,it);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);

        int m=connections.size();

        if(n-1>m) return -1;

        for(int i=0;i<m;i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }

        vector<int>vis(n,0);
        int cnt=0;

        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                cnt++;
                dfs(adj,vis,i);
            }
        }

        return cnt-1;
    }
};