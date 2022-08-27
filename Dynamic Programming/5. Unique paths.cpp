

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

    return dp[0][0];
}