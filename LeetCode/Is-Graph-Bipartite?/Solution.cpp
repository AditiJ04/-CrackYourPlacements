class Solution {
public:
    bool dfs(vector<vector<int>>&adj,vector<int>&vis,int idx,int color)
    {
        vis[idx]=color;

        for(auto it:adj[idx])
        {
            if(vis[it]==-1)
            {
                if(dfs(adj,vis,it,!color)==false)
                {
                    return false;
                }
            }

            else if(vis[it]==color)
            {
                return false;
            }
        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {

        int n=graph.size();
        int m=graph[0].size();

        vector<vector<int>>adj(n);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<graph[i].size();j++)
            {
                adj[i].push_back(graph[i][j]);
            }
        }
        vector<int>vis(n,-1);

        for(int k=0;k<n;k++)
        {
            if(vis[k]==-1)
            {
                if(!dfs(adj,vis,k,0))
                {
                    return false;
                }
            }
        }

        return true;
    }
};