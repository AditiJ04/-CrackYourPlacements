class Disjoint{
    vector<int>parent,size;

    public:

    Disjoint(int n)
    {
        parent.resize(n);
        size.resize(n);

        for(int i=0;i<n;i++)
        {
            parent[i]=i;
            size[i]=1;
        }
    }

    int findUParent(int node)
    {
        if(node==parent[node])
        {
            return node;
        }
        return parent[node]=findUParent(parent[node]);
    }

    void unionBySize(int u,int v)
    {
        int ulp_u=findUParent(u);
        int ulp_v=findUParent(v);

        if(size[ulp_u]<size[ulp_v])
        {
            size[ulp_v]+=size[ulp_u];
            parent[ulp_u]=ulp_v;
        }
        else
        {
            size[ulp_u]+=size[ulp_v];
            parent[ulp_v]=ulp_u;
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();

        Disjoint ds(n);
        int cnt=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1])
                {
                    int u=ds.findUParent(i);
                    int v=ds.findUParent(j);

                    if(u!=v)
                    {
                        ds.unionBySize(u,v);
                        cnt++;
                    }
                }
            }
        }

        return cnt;
    }
};