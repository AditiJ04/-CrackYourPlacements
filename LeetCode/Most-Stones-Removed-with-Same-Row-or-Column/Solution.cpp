class Solution {
public:
    
    void dfs(vector<vector<int>>&stones,int idx,vector<bool>&vis)
    {
        vis[idx]=true;
        for(int k=0;k<stones.size();k++)
        {
            int r=stones[idx][0];
            int c=stones[idx][1];
            if((vis[k]==false) && (stones[k][0]==r || stones[k][1]==c))
            {
                dfs(stones,k,vis);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        int grps=0;

        vector<bool>vis(n,false);

        for(int i=0;i<n;i++)
        {
            if(vis[i]==true)
            {
                continue;
            }

            dfs(stones,i,vis);
            grps++;
        }

        return n-grps;
    }
};