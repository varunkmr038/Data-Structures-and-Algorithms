
// check that only * should be present
bool checkStar(string& s, int i) {

  int n = s.size();
  while (i < n) {
    if (s[i] != '*') return false;
    i++;
  }
  return true;
}

bool solve(string & s, string & p , int i, int j, vector<vector<int>>& dp) {

  int m = s.size(), n = p.size();

  if (dp[i][j] != -1) return dp[i][j];


  // this is base case
  // check there should only be stars left in patter
  if (i == m) return dp[i][j] = checkStar(p, j);

  if (j == n) return dp[i][j] = false; // there some string left


  bool ans = 0;
  if (p[j] == '*') {

    // dont match star
    ans = solve(s, p, i, j + 1, dp);

    ans = ans or solve(s, p, i + 1, j, dp); // match cur with *

  }
  else if (p[j] == '?') {
    ans = solve(s, p, i + 1, j + 1, dp); // no choice you have to match cur char
  }
  else {

    if (s[i] != p[j]) ans = 0;

    else ans = solve(s, p, i + 1, j + 1, dp);
  }
  return dp[i][j] = ans;
}

//  Time: O(N*M) Space: O(N*M) Memoized 2d DP
bool isMatch(string s, string p) {

  int m = s.size(), n = p.size();

  vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
  return solve(s, p, 0, 0, dp);
}


// ------------------------------------------------------------------------------------------------------------

//  Time: O(N*M) Space: O(N*M) Bottom up 2d DP
bool isMatch(string s, string p) {

  int m = s.size(), n = p.size();

  vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, 0));
  dp[m][n] = 1;

  // check star base case
  for (int j = n - 1; j >= 0 ; j--) {
    if (p[j] != '*') dp[m][j] = 0;
    else dp[m][j] = dp[m][j + 1]; // depends on aage wale pe
  }

  for (int i = m - 1; i >= 0; i--) {

    for (int j = n - 1; j >= 0; j--) {

      if (p[j] == '*') {

        // dont match star
        dp[i][j] = dp[i][j + 1];

        dp[i][j] = dp[i][j] or dp[i + 1][j]; // match cur with *

      }
      else if (p[j] == '?') {
        dp[i][j] = dp[i + 1][j + 1]; // no choice you have to match cur char
      }
      else {

        if (s[i] != p[j]) dp[i][j] = 0;

        else dp[i][j] = dp[i + 1][j + 1];
      }
    }

  }

  return dp[0][0];
}
