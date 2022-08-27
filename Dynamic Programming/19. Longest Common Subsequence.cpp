
int solve(string& text1, string& text2, int i, int j, vector<vector<int>>& dp) {

    int m = text1.size(), n = text2.size();

    if (i == m or j == n) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    int ans = 0;

    if (text1[i] == text2[j]) ans = 1 + solve(text1, text2, i + 1, j + 1, dp);
    else {
        int sub1 = solve(text1, text2, i + 1, j, dp);
        int sub2 = solve(text1, text2, i, j + 1, dp);

        ans = max(sub1, sub2);
    }

    return dp[i][j] = ans;
}


//  TIme: O(N*M)  Space: O(N*M) Memoized 2d Dp
int longestCommonSubsequence(string text1, string text2) {

    int m = text1.size(), n = text2.size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    return solve(text1, text2, 0, 0, dp);
}

// --------------------------------------------------------------------------------


//  TIme: O(N*M)  Space: O(N*M) Bottom Up 2d Dp
int longestCommonSubsequence(string text1, string text2) {

    int m = text1.size(), n = text2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

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