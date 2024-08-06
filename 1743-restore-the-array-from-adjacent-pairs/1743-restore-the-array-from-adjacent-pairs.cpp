class Solution {
public:
    void dfs(unordered_map<int,vector<int>> &mp, set<int>&vis, int sv, vector<int> &ans){
        
        if(vis.find(sv)!=vis.end())
        {
            return;
        }
        ans.push_back(sv);
        vis.insert(sv);

        for(int x:mp[sv])
        {
            dfs(mp,vis,x,ans);
        }
    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        vector<int> ans;
        set<int>vis;
        unordered_map<int,vector<int>> mp;
        for(auto x:adjacentPairs){
            mp[x[0]].push_back(x[1]);
            mp[x[1]].push_back(x[0]);
        }
        int start_node=0;
        for(auto x:mp){
            if(x.second.size()==1){
                start_node=x.first;
                break;
            }
        }
        dfs(mp,vis,start_node,ans);
        return ans;
    }
};