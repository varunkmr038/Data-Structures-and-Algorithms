
int solve(vector<int>& cuts, int i, int j, vector<vector<int>>& dp) {

    if (i > j) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    int ans = INT_MAX;
    for (int k = i; k <= j; k++) {
        int cuttingCost = cuts[j + 1] - (i == 0 ? 0 : cuts[i - 1]);

        int subProblem = solve(cuts, i, k - 1, dp) + solve(cuts, k + 1, j, dp);

        ans = min(ans, cuttingCost + subProblem);
    }
    return dp[i][j] = ans;
}


//  Time: O(N^3)  Space: O(N^2) Memoized 2d Dp
int minCost(int n, vector<int>& cuts) {

    int m = cuts.size();

    sort(cuts.begin(), cuts.end());

    cuts.push_back(n);
    // cut array - 0   1 3 4 5   7
    vector<vector<int>> dp(m + 1, vector<int>(m + 1, -1));
    return solve(cuts, 0, m - 1, dp);
}

// ------------------------------------------------------------------------

// striver

//  Time: O(N^3)  Space: O(N^2) Bottom up 2d Dp
int minCost(int n, vector<int>& cuts) {

    int m = cuts.size();

    sort(cuts.begin(), cuts.end());
    cuts.push_back(n);
    // cut array - 0   1 3 4 5   7
    vector<vector<int>> dp(m + 1, vector<int>(m + 1, 0));

    for (int i = m - 1; i >= 0; i--) {

        for (int j = i; j < m; j++) {

            int ans = INT_MAX;
            for (int k = i; k <= j; k++) {
                int cuttingCost = cuts[j + 1] - (i == 0 ? 0 : cuts[i - 1]);

                int subProblem = (k - 1 >= 0 ? dp[i][k - 1] : 0) + dp[k + 1][j];

                ans = min(ans, cuttingCost + subProblem);
            }
            dp[i][j] = ans;
        }
    }


    return dp[0][m - 1];
}


// ------------------------------------------------------------------------

// by length building dp

//  Time: O(N^3)  Space: O(N^2) Bottom up 2d Dp
int minCost(int n, vector<int>& cuts) {

    int m = cuts.size();

    sort(cuts.begin(), cuts.end());
    cuts.push_back(n);
    // cut array - 0   1 3 4 5   7
    vector<vector<int>> dp(m + 1, vector<int>(m + 1, 0));

    for (int len = 1; len <= m; len++) {

        for (int i = 0; i <= m - len; i++) {
            int j = i + len - 1;

            int ans = INT_MAX;
            for (int k = i; k <= j; k++) {
                int cuttingCost = cuts[j + 1] - (i == 0 ? 0 : cuts[i - 1]);

                int subProblem = (k - 1 >= 0 ? dp[i][k - 1] : 0) + dp[k + 1][j];

                ans = min(ans, cuttingCost + subProblem);
            }
            dp[i][j] = ans;
        }
    }


    return dp[0][m - 1];
}