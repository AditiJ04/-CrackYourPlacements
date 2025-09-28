class Solution {
public:
   vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();

    vector<vector<int>> vis(n, vector<int>(m, -1));
    queue<pair<int, int>> que;

    vector<int> row = {0, 0, 1, -1}; // directions: right, left, down, up
    vector<int> col = {1, -1, 0, 0};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 0) {
                vis[i][j] = 0;
                que.push({i, j}); // typo was here: you wrote que,push instead of que.push
            }
        }
    }

    while (!que.empty()) {
        auto ele = que.front();
        int i = ele.first;
        int j = ele.second;
        que.pop();

        for (int k = 0; k < 4; k++) {
            int nr = i + row[k];
            int nc = j + col[k];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                if (vis[nr][nc] == -1) { // should visit only unvisited cells
                    vis[nr][nc] = vis[i][j] + 1;
                    que.push({nr, nc});
                }
            }
        }
    }

    return vis;
}
};