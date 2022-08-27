bool dfs(vector<vector<char>>& board, vector<vector<bool>>& vis, int i, int j) {
  int m = board.size(), n = board[0].size();

  if (i < 0 or j < 0 or i == m or j == n) return false;
  if (board[i][j] == 'X' or vis[i][j] == 1) return true;

  vis[i][j] = 1;
  bool ans = 1;

  ans &= dfs(board, vis, i + 1, j);
  ans &= dfs(board, vis, i - 1, j);
  ans &= dfs(board, vis, i, j + 1);
  ans &= dfs(board, vis, i, j - 1);

  return ans;
}

void markRegions(vector<vector<char>>& board, vector<vector<bool>>& vis, int i, int j) {
  int m = board.size(), n = board[0].size();

  if (i < 0 or j < 0 or i == m or j == n) return;
  if (board[i][j] == 'X' or vis[i][j] == 1) return;

  board[i][j] = 'X';
  vis[i][j] = 1;

  markRegions(board, vis, i + 1, j);
  markRegions(board, vis, i - 1, j);
  markRegions(board, vis, i, j + 1);
  markRegions(board, vis, i, j - 1);
}


//  Time: O(3*M*N) Space: O(M*N)
void solve(vector<vector<char>>& board) {

  int m = board.size(), n = board[0].size();

  vector<pair<int, int>> indexes;

  vector<vector<bool>> vis(m, vector<bool>(n, 0));

  for (int i = 0; i < m; i++) {

    for (int j = 0; j < n; j++) {
      if (board[i][j] == 'X' or vis[i][j] == 1) continue;

      // that means i have to explore current O
      bool ans = dfs(board, vis, i, j);
      if (ans) {
        indexes.push_back({i, j});
      }
    }
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++)vis[i][j] = 0;
  }


  // now mark the valid O to X
  for (auto x : indexes) {
    markRegions(board, vis, x.first, x.second);
  }

}


// ----------------------------------------------------------------------------------

void dfs(vector<vector<char>>& board, int i, int j) {
  int m = board.size(), n = board[0].size();

  if (i < 0 or j < 0 or i == m or j == n) return ;
  if (board[i][j] == 'X' or board[i][j] == '1') return ;

  board[i][j] = '1';

  dfs(board, i + 1, j);
  dfs(board, i - 1, j);
  dfs(board, i, j + 1);
  dfs(board , i, j - 1);

}



//  Time: O(M*N) Space: O(M*N) DFS Boundary traversal
void solve(vector<vector<char>>& board) {

  int m = board.size(), n = board[0].size();


  for (int i = 0; i < m; i++) {
    dfs(board, i, 0);
    dfs(board, i, n - 1);
  }

  for (int i = 0; i < n; i++) {
    dfs(board, 0, i);
    dfs(board, m - 1, i);
  }


  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (board[i][j] == '1') board[i][j] = 'O';
      else if (board[i][j] == 'O') board[i][j] = 'X';
    }
  }

}