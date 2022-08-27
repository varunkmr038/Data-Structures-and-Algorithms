
int solve(string& s, string& t, int i, int j, vector<vector<int>>& dp) {

  int m = s.size(), n = t.size();

  // have match all the chars of t
  if (j == n) return 1;
  if (i == m) return 0;
  if (dp[i][j] != -1) return dp[i][j];

  int ans = 0;

  if (s[i] == t[j]) ans += solve(s, t, i + 1, j + 1, dp);

  ans += solve(s, t, i + 1, j, dp); // otherwise not including cur char

  return dp[i][j] = ans;
}

//  Time: O(N*M)  Space: O(N*M) Memoized 2d Dp
int numDistinct(string s, string t) {

  int m = s.size(), n = t.size();

  vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
  return solve(s, t, 0, 0, dp);
}


// -----------------------------------------------------------------------------------

//  Time: O(N*M)  Space: O(N*M) Bottom UP 2d Dp
int numDistinct(string s, string t) {

  int m = s.size(), n = t.size();

  vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
  for (int i = 0; i <= m; i++) {
    dp[i][n] = 1;
  }

  for (int i = m - 1; i >= 0; i--) {

    for (int j = n - 1; j >= 0; j--) {

      if (s[i] == t[j])
        dp[i][j] = dp[i + 1][j + 1];

      dp[i][j] += dp[i + 1][j];
    }

  }

  return dp[0][0];
}

// -----------------------------------------------------------------------------------

//  Time: O(N*M)  Space: O(M)  Space Optimised Bottom UP 1d Dp
int numDistinct(string s, string t) {

  int m = s.size(), n = t.size();

  vector<int> dp(m + 1, 0);
  dp[n] = 1;

  for (int i = m - 1; i >= 0; i--) {

    for (int j = 0; j <= n; j++) {

      if (s[i] == t[j])
        dp[j] += dp[j + 1];

    }
  }

  return dp[0];
}
