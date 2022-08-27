
int longestCommonSubsequence(string text1, string text2, vector<vector<int>>& dp) {

  int m = text1.size(), n = text2.size();

  for (int i = m - 1; i >= 0; i--) {
    for (int j = n - 1; j >= 0; j--) {
      int ans = 0;

      if (text1[i] == text2[j]) ans = 1 + dp[i + 1][j + 1];
      else {
        int sub1 = dp[i + 1][j];
        int sub2 = dp[i][j + 1];
        ans = max(sub1, sub2);
      }
      dp[i][j] = ans;
    }
  }
  return dp[0][0];
}

string printLCS(string text1, string text2) {

  int m = text1.size(), n = text2.size();

  vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
  longestCommonSubsequence(text1, text2, dp);

  string ans = "";
  int i = 0, j = 0;

  while (i < m and j < n) {

    if (text1[i] == text2[j]) {
      ans += text1[i];
      i++;
      j++;
    }
    else {
      if (dp[i + 1][j] > dp[i][j + 1]) i++;
      else j++;
    }
  }
  return ans;
}

//  Time: O(N*M) Space: O(N*M) Bottom Up 2d DP
string shortestCommonSupersequence(string str1, string str2) {

  int n1 = str1.size(), n2 = str2.size();

  string ans = "";

  string lcs = printLCS(str1, str2);

  if (lcs.size() == 0) return str1 + str2;

  int j = 0, k = 0;
  for (int i = 0; i < lcs.size() + 1; i++) {

    char curChar = i == lcs.size() ? '$' : lcs[i];

    while (j < n1 and str1[j] != curChar) {
      ans += str1[j];
      j++;
    }
    j++;

    while (k < n2 and str2[k] != curChar) {
      ans += str2[k];
      k++;
    }
    k++;

    if (curChar != '$')
      ans += curChar;
  }

  return ans;
}

// ---------------------------------------------------------------------------------------------



int longestCommonSubsequence(string text1, string text2, vector<vector<int>>& dp) {

  int m = text1.size(), n = text2.size();

  for (int i = m - 1; i >= 0; i--) {
    for (int j = n - 1; j >= 0; j--) {
      int ans = 0;

      if (text1[i] == text2[j]) ans = 1 + dp[i + 1][j + 1];
      else {
        int sub1 = dp[i + 1][j];
        int sub2 = dp[i][j + 1];
        ans = max(sub1, sub2);
      }
      dp[i][j] = ans;
    }
  }
  return dp[0][0];
}

string printSCS(string text1, string text2) {

  int m = text1.size(), n = text2.size();

  vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
  longestCommonSubsequence(text1, text2, dp);

  string ans = "";
  int i = 0, j = 0;

  while (i < m and j < n) {

    if (text1[i] == text2[j]) {
      ans += text1[i];
      i++;
      j++;
    }
    else {
      if (dp[i + 1][j] > dp[i][j + 1]) {
        ans += text1[i++];
      }
      else ans += text2[j++];
    }
  }

  while (i < m) ans += text1[i++];
  while (j < n) ans += text2[j++];

  return ans;
}

//  Time: O(N*M) Space: O(N*M) Bottom Up 2d DP by making modifications in LCS code
string shortestCommonSupersequence(string str1, string str2) {

  int n1 = str1.size(), n2 = str2.size();

  return printSCS(str1, str2);
}