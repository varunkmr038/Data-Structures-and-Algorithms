// Time: O(N^2) Space: O(N^2) Using 2D Dp
int uniquePaths(int m, int n) {

  vector<vector<int>> dp(m, vector<int> (n, -1));

  return solve(0, 0, m - 1, n - 1, dp);
}

int solve(int sr, int sc, int er, int ec, vector<vector<int>>& dp) {
  if (sr == er and sc == ec) return 1;

  if (sr > er or sc > ec) return 0;

  if (dp[sr][sc] != -1) return dp[sr][sc];

  int goDown = solve(sr + 1, sc, er, ec, dp);
  int goRight = solve(sr, sc + 1, er, ec, dp);

  return dp[sr][sc] = goDown + goRight;

}

// -------------------------------------------------------------------------------

// Time: O(N^2) Space: O(N^2) Using 2D  Bottom Up Dp
int uniquePaths(int m, int n) {

  vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));
  dp[m - 1][n - 1] = 1;

  for (int i = m - 1; i >= 0; i--) {
    for (int j = n - 1; j >= 0; j--) {
      dp[i][j] += dp[i + 1][j] + dp[i][j + 1];
    }
  }

  return dp[0][0];
}

// -------------------------------------------------------------------------------------

// Time: O(N^2) Space: O(N) Space Optimised 1D  Bottom Up Dp
int uniquePaths(int m, int n) {

  vector<int> dp(n, 0);
  dp[n - 1] = 1;

  for (int i = m - 1; i >= 0; i--) {

    vector<int> temp(n, 0);
    for (int j = n - 1; j >= 0; j--) {
      temp[j] = dp[j];
      if (j < n - 1) temp[j] += temp[j + 1];
    }

    for (int j = 0; j < n; j++) dp[j] = temp[j];
  }

  return dp[0];
}