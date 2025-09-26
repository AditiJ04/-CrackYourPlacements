class Solution {
public:

    pair<long long ,long long>help(int u,int p,vector<vector<int>>&adj,vector<int>&cost)
    {
        bool isLeaf=true;

        vector<long long>childsum,childcnt;
        long long mxsum=0LL;
        long long totalcnt=0;

        for(auto v:adj[u])
        {
            if(v==p) continue;
            isLeaf=false;

            auto curr=help(v,u,adj,cost);
            childsum.push_back(curr.first);
            childcnt.push_back(curr.second);
            mxsum=max(mxsum,curr.first);
            totalcnt+=curr.second;
        }
        if(isLeaf) 
        {
            return make_pair(cost[u],0);
        }

        long long extra=0LL;
        for(auto i:childsum)
        {
            if(i<mxsum)
            {
                extra++;
            }
        }

        return make_pair(cost[u]+mxsum,totalcnt+extra);
    }
    int minIncrease(int n, vector<vector<int>>& edges, vector<int>& cost) {
        vector<vector<int>>adj(n);

        for(auto i:edges)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        auto ans=help(0,-1,adj,cost);

        return ans.second;

    }
};