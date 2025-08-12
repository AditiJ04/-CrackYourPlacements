class Solution {
public:
    bool dfs(int node,int n,vector<int>adj[],vector<int>&color,int col)
    {
        color[node]=col;

        for(auto it:adj[node])
        {
            if(color[it]==-1)
            {
                if((dfs(it,n,adj,color,!col))==false)
                {
                    return false;
                }
            }
            else if(color[it]==col)
            {
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n=graph.size();

        vector<int>color(n,-1);

        vector<int>adj[n];

        for(int i=0;i<n;i++)
        {
            for(int num:graph[i])
            {
                adj[i].push_back(num);
            }
        }

        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
            if(dfs(i,n,adj,color,0)==false)
            {
                return false;
            }
            }
        }
        return true;
    }
};