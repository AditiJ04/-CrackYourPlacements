//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool Cycle(vector<int>adj[],vector<bool>&vis,vector<bool>&dfsvis,int node)
    {
        vis[node]=true;
        dfsvis[node]=true;
        
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                if(Cycle(adj,vis,dfsvis,it))
                {
                    return true;
                }
            }
            
            else if(dfsvis[it])
            {
                return true;
            }
        }
        
        dfsvis[node]=false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        
        vector<bool>vis(V,false);
        vector<bool>dfsvis(V,false);
        
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(Cycle(adj,vis,dfsvis,i))
                {
                    return true;
                }
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends