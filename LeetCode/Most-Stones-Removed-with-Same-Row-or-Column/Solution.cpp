class Solution {
public:
    vector<int>parent;
    vector<int>rank;

    int findPar(int node)
    {
        if(node==parent[node])
        {
            return node;
        }

        return parent[node]=findPar(parent[node]);
    }

    void unionByRank(int u,int v)
    {
        int ulp_u=findPar(u);
        int ulp_v=findPar(v);

        if(ulp_u==ulp_v)
        {
            return;
        }

        if(rank[ulp_u]<rank[ulp_v])
        {
            parent[ulp_u]=ulp_v;
            rank[ulp_v]++;
        }
        else if(rank[ulp_u]>rank[ulp_v])
        {
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
        else
        {
            parent[ulp_u]=ulp_v;
            rank[ulp_v]++;
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();

        parent.resize(n);
        rank.resize(n,0);

        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }

        int grps=0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1])
                {
                    unionByRank(i,j);
                }
            }
        }

        for(int i=0;i<n;i++)
        {
            if(i==parent[i])
            {
                grps++;
            }
        }

        return n-grps;
    }
};