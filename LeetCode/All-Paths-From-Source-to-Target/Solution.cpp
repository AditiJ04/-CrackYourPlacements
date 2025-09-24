class Solution {
public:
    void dfs(int src,int dest,vector<vector<int>>&graph,vector<int>&ans,vector<vector<int>>&res)
    {
        ans.push_back(src);

        if(src==dest)
        {
            res.push_back(ans);
            ans.pop_back();
            return;
        }

        for(auto it:graph[src])
        {
            dfs(it,dest,graph,ans,res);
        }
        ans.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();

        vector<vector<int>>res;
        vector<int>ans;

        dfs(0,n-1,graph,ans,res);
        return res;
    }
};