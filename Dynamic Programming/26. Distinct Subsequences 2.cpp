

//  Time: O(N*N) Space: O(N) Space Optimised 1d DP
int distinctSubseqII(string s) {

  int n = s.size();
  int mod = 1e9 + 7;

  vector<int> dp(n, 0);
  dp[0] = 2;

  for (int i = 1; i < n; i++) {

    dp[i] = (1LL * dp[i - 1] * 2) % mod;
    for (int j = i - 1; j >= 0; j--) {

      if (s[i] == s[j]) {
        dp[i] = (dp[i] - (j > 0 ? dp[j - 1] : 1) + mod) % mod;
        break;
      }
    }
  }
  return dp[n - 1] - 1;
}

// --------------------------------------------------------------



//  Time: O(N) Space: O(N)Time and   Space Optimised 1d DP
int distinctSubseqII(string s) {

  int n = s.size();
  int mod = 1e9 + 7;

  vector<int> dp(n, 0);
  dp[0] = 2;
  vector<int> freq(26, 0);
  freq[s[0] - 'a'] = 1;

  for (int i = 1; i < n; i++) {

    dp[i] = (1LL * dp[i - 1] * 2) % mod;

    dp[i] = (dp[i] -  freq[s[i] - 'a'] + mod) % mod;

    freq[s[i] - 'a'] = dp[i - 1]; // saving the prev value
  }
  return dp[n - 1] - 1;
}