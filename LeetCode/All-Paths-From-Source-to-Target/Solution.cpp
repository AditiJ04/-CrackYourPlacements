class Solution {
public:

    vector<vector<int>>res;
    void dfs(vector<vector<int>>&graph,vector<vector<int>>&adj,vector<int>&v,int s)
    {
        v.push_back(s);

        if(s==graph.size()-1)
        {
            res.push_back(v);
            return;
        }
        for(auto it:adj[s])
        {
            dfs(graph,adj,v,it);
            v.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        int m=graph[0].size();
        vector<vector<int>>adj(n);
        vector<vector<int>>vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<graph[i].size();j++)
            {
                adj[i].push_back(graph[i][j]);
            }
        }

        vector<int>v;
        dfs(graph,adj,v,0);

        return res;
    }
};


//0->1,2
//1->3
//2->3

//0->4,3,1
//1->3,2,4
//2->3
//3->4