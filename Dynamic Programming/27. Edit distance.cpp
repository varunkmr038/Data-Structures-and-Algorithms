
int solve(string& word1, string& word2, int i , int j, vector<vector<int>>& dp) {

  int m = word1.size(), n = word2.size();

  if (j == n) return m - i;
  if (i == m) return n - j;  // so at this point you have insert rest chars at the end

  if (dp[i][j] != -1) return dp[i][j];

  if (word1[i] == word2[j]) return dp[i][j] = solve(word1, word2, i + 1, j + 1, dp);

  int insert = 1 + solve(word1, word2, i, j + 1, dp);
  int remove = 1 + solve(word1, word2, i + 1, j, dp);
  int replace = 1 + solve(word1, word2, i + 1, j + 1, dp);

  return dp[i][j] = min({insert, remove, replace});
}


//  Time: O(N*M) Space: O(N*M) Memoized 2d DP
int minDistance(string word1, string word2) {

  int m = word1.size(), n = word2.size();

  vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

  return solve(word1, word2, 0, 0, dp);

}

// --------------------------------------------------------------



//  Time: O(N*M) Space: O(N*M) Bottm Up 2d DP
int minDistance(string word1, string word2) {

  int m = word1.size(), n = word2.size();

  vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

  for (int i = 0; i <= m; i++) dp[i][n] = m - i;
  for (int i = 0; i <= n; i++) dp[m][i] = n - i;

  for (int i = m - 1; i >= 0; i--) {

    for (int j = n - 1; j >= 0; j--) {
      if (word1[i] == word2[j]) dp[i][j] = dp[i + 1][j + 1];

      else {
        int insert = 1 + dp[i][j + 1];
        int remove = 1 + dp[i + 1][j];
        int replace = 1 + dp[i + 1][j + 1];

        dp[i][j] = min({insert, remove, replace});
      }
    }

  }

  return dp[0][0];

}

// --------------------------------------------------------------


