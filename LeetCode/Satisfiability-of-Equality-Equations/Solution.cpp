class DisjointSet{
    vector<int>parent,size;

    public:

    DisjointSet()
    {
        parent.resize(26,0);
        size.resize(26,0);

        for(int i=0;i<26;i++)
        {
            parent[i]=i;
            size[i]=1;
        }
    }

    int findParent(int node)
    {
        if(node==parent[node])
        {
            return node;
        }

        return parent[node]=findParent(parent[node]);
    }

    void unionBySize(int u,int v)
    {
        int ulp_u=findParent(u);
        int ulp_v=findParent(v);

        if(ulp_u==ulp_v) return;

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
    bool equationsPossible(vector<string>& equations) {
       int n=equations.size();

       DisjointSet st;
       for(auto &eq:equations)
       {
           if(eq[1]=='=')
           {
             int a=eq[0]-'a';
             int b=eq[3]-'a';

             st.unionBySize(a,b);
           }
       }

       for(auto &eq:equations)
       {
           if(eq[1]=='!')
           {
             int a=eq[0]-'a';
             int b=eq[3]-'a';

             if(st.findParent(a)==st.findParent(b))
             {
                return false;
             }
           }
       }

       return true;
    }
};