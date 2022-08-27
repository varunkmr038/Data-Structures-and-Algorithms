
// marking the current island visited
void markIslandVisited(vector<vector<int>>& grid, int i, int j , vector<vector<int>>& vis, vector<pair<int, int>>& firstIsland) {
  int n = grid.size();
  vis[i][j] = 1;
  firstIsland.push_back({i, j}); // pushing the current island coordinates

  // left up right down
  int dx[] = { 0, -1, 0, 1};
  int dy[] = { -1, 0, 1, 0 };

  for (int idx = 0; idx < 4; idx++) {
    int x = i + dx[idx];
    int y = j + dy[idx];

    if (x<0 or y<0 or x >= n or y >= n) continue;

    if (!vis[x][y] and grid[x][y] == 1) // it should be island
      markIslandVisited(grid, x, y, vis, firstIsland);
  }
}

// single source shortest path
int findMinBFS(vector<vector<int>>& grid, vector<pair<int, int>>& firstIsland, vector<vector<int>>& vis) {
  int n = grid.size();

  int ans = INT_MAX;
  int dx[] = { 0, -1, 0, 1};
  int dy[] = { -1, 0, 1, 0 };

  queue<pair<int, int>> q;// {i,j}
  vector<vector<int>> dis(n, vector<int> (n, INT_MAX));

  // simultaneosuly explore the matrix
  // taking every 1 as source in the first island and explore simultaneously
  for (int i = 0; i < firstIsland.size(); i++) {
    q.push(firstIsland[i]);
    dis[firstIsland[i].first][firstIsland[i].second] = 0;
  }

  while (!q.empty()) {

    auto cur = q.front();
    q.pop();


    for (int idx = 0; idx < 4; idx++) {
      int x = cur.first + dx[idx];
      int y = cur.second + dy[idx];

      if (x<0 or y<0 or x >= n or y >= n or vis[x][y]) continue;

      // unvisited
      if (grid[x][y] == 1) { // now found the second island
        return dis[cur.first][cur.second];
      }

      // otherwise grid[x][y]=0 so explore
      q.push({x, y});
      vis[x][y] = 1;
      dis[x][y] = dis[cur.first][cur.second] + 1;

    }

  }
  return ans;
}

// simultaneosuly explore the all island and doing bfs and finding min dist to other island
int solve(vector<vector<int>>& grid, int i, int j) {

  int n = grid.size();

  vector<vector<int>> vis(n, vector<int>(n, 0));
  vector<pair<int, int>> firstIsland;

  markIslandVisited(grid, i, j, vis, firstIsland);

  return findMinBFS(grid, firstIsland, vis);
}


//  Time: O(N^2) Space: O(2*N^2) Using bfs flood fill
int shortestBridge(vector<vector<int>>& grid) {

  int n = grid.size();

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (grid[i][j] == 0) continue;

      return solve(grid, i, j);
    }
  }
  return 0;
}
