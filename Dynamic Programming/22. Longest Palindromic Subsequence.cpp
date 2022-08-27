
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

//  TIme: O(N*N)  Space: O(N*N) Bottom Up 2d Dp
int longestPalindromeSubseq(string s) {

    int n = s.size();
    string t = s;

    reverse(t.begin(), t.end());
    //  Using LCS
    return longestCommonSubsequence(s, t);
}
// --------------------------------------------------------------------------------

int solve(string& s, int i, int j, vector<vector<int>>& dp) {

    if (i == j) return 1;
    if (i > j) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    int ans = 0;
    if (s[i] == s[j]) ans = solve(s, i + 1, j - 1, dp) + 2;

    else {
        ans = max(solve(s, i + 1, j, dp), solve(s, i, j - 1, dp));
    }
    return dp[i][j] = ans;
}


//  TIme: O(N*N)  Space: O(N*N) Memoized 2d Dp
int longestPalindromeSubseq(string s) {

    int n = s.size();

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return solve(s, 0, n - 1, dp);
}
// --------------------------------------------------------------------------------



//  TIme: O(N*N)  Space: O(N) bottom up 1d Dp
int longestPalindromeSubseq(string s) {

    int n = s.size();

    vector<int> dp(n + 1, 0);
    dp[n - 1] = 1;

    for (int i = n - 1; i >= 0; i--) {

        vector<int> temp(n + 1, 0);
        temp[i] = 1; // i=j case

        for (int j = i + 1; j < n; j++) {
            if (s[i] == s[j]) temp[j] += 2 + dp[j - 1];
            else temp[j] += max(temp[j - 1], dp[j]);
        }

        dp = temp;
    }

    return dp[n - 1];
}
// --------------------------------------------------------------------------------

