class Solution {
public:
    bool dfs(int node,int col,vector<int>&color,vector<int>adj[])
    {
        
        color[node]=col;
        

        for(auto c:adj[node])
        {
            if(color[c]==-1)
            {
                if(dfs(c,!col,color,adj)==false)
                {
                    return false;
                }
            }
            else if(color[c]==col)
            {
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>adj[n];
        for(int i=0;i<n;i++)
        {
            for(auto it:graph[i])
            {
                adj[i].push_back(it);
            }
        }

        vector<int>color(n,-1);
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
        if(dfs(i,0,color,adj)==false)
        {
            return false;
        }
            }
        }
        return true;
    }
};