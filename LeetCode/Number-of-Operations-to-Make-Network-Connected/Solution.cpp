class DisjointSet {
public:
    vector<int> rank, parent, size;
	DisjointSet(int n) {
		rank.resize(n + 1, 0);
		size.resize(n + 1);
		parent.resize(n + 1);

		for (int i = 0; i < n; i++) {
			parent[i] = i;
			size[i] = 1;
		}
	}

	// finding ultimate parent
	int findUltimateParent(int node) {
		if (node == parent[node])
			return node;
		return parent[node] = findUltimateParent(parent[node]);
	}

	void unionByRank(int u, int v) {
		int UltimateParent_u = findUltimateParent(u);
		int UltimateParent_v = findUltimateParent(v);

		if (UltimateParent_u == UltimateParent_v)
			return;

		if (rank[UltimateParent_u] < rank[UltimateParent_v])
			parent[UltimateParent_u] = UltimateParent_v;
		else if (rank[UltimateParent_v] < rank[UltimateParent_u])
			parent[UltimateParent_v] = UltimateParent_u;
		else {
			parent[UltimateParent_v] = UltimateParent_u;
			rank[UltimateParent_u]++;
		}
	}

	void unionBySize(int u, int v) {
		int UltimateParent_u = findUltimateParent(u);
		int UltimateParent_v = findUltimateParent(v);

		if (UltimateParent_u == UltimateParent_v)
			return;

		if (rank[UltimateParent_u] < rank[UltimateParent_v]) {
			parent[UltimateParent_u] = UltimateParent_v;
			size[UltimateParent_v] += size[UltimateParent_u];
		} else {
			parent[UltimateParent_v] = UltimateParent_u;
			size[UltimateParent_u] += size[UltimateParent_v];
		}
	}
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& edge) {
        DisjointSet ds(n);
        
        int cntExtras = 0;
        for(auto it: edge) {
            int u = it[0];
            int v = it[1];
            
            if(ds.findUltimateParent(u) == ds.findUltimateParent(v)) {
                cntExtras++;
            } else { 
                ds.unionBySize(u, v);
            }
        }
        
        int cnt = 0;
        for(int i=0;i<n;i++) {
            if(ds.parent[i] == i) {
                cnt++;
            }
        }
        int ans = cnt -1; 
        if(cntExtras >= ans) {
            return ans;
        }
        return -1;
    }
};