//  Time: O(M*N) Space: O(M*N) Using simultaneous bfs approach
int orangesRotting(vector<vector<int>>& grid) {

    int m = grid.size(), n = grid[0].size();
    int ans = 0;

    int freshOranges = 0;
    // {i,j} which stores rotten oranges
    queue<pair<int, int>>q;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) freshOranges++;
            else if (grid[i][j] == 2) q.push({i, j}); // rotten orange
        }
    }

    if (freshOranges == 0) return 0;

    vector<vector<int>> vis(m, vector<int>(n, 0));

    // do the bfs level by level
    while (!q.empty()) {

        int len = q.size();
        if (freshOranges == 0) break;

        while (len--) {
            auto cur = q.front();
            q.pop();

            int curX = cur.first, curY = cur.second;
            if (vis[curX][curY] == 1) continue;

            vis[curX][curY] = 1;

            int dx[] = { -1, 1, 0, 0};
            int dy[] = {0, 0, -1, 1};

            for (int i = 0; i < 4; i++) {
                int x = curX + dx[i];
                int y = curY  + dy[i];

                if (x<0 or y<0 or x >= m or y >= n) continue;

                if (grid[x][y] == 1) {
                    grid[x][y] = 2;  // make it rotten
                    freshOranges--;
                    q.push({x, y});
                }
            }

        }
        ans++; // increment time interval
    }

    return freshOranges == 0 ? ans : -1;
}