

//  TIme: O(N*M)  Space: O(N*M) Bottom Up 2d Dp
int lcs(string &s1, string &s2) {

    int n1 = s1.size(), n2 = s2.size();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

    int ans = 0;

    for (int i = n1 - 1; i >= 0; i--) {
        for (int j = n2 - 1; j >= 0; j--) {

            if (s1[i] == s2[j]) dp[i][j] = 1 + dp[i + 1][j + 1];
            else dp[i][j] = 0;

            ans = max(ans, dp[i][j]);
        }

    }

    return ans;
}
// --------------------------------------------------------------------------------



//  TIme: O(N*M)  Space: O(N) Bottom Up 1d Dp
int lcs(string &s1, string &s2) {

    int n1 = s1.size(), n2 = s2.size();
    vector<int> dp(n2 + 1, 0);

    int ans = 0;

    for (int i = n1 - 1; i >= 0; i--) {
        for (int j = 0; j < n2; j++) {

            if (s1[i] == s2[j]) dp[j] = 1 + dp[j + 1];
            else dp[j] = 0;

            ans = max(ans, dp[j]);
        }

    }

    return ans;
}



// --------------------------------------------------------------
