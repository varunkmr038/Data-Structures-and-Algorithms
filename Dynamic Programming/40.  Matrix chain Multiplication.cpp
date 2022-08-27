
int solve(vector<int>& arr, int i, int j, vector<vector<int>>& dp) {

    if (i >= j) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    int ans = INT_MAX;
    for (int k = i; k < j; k++) {
        int costOfPartition = arr[i - 1] * arr[k] * arr[j];

        int subProblem = solve(arr, i, k, dp) + solve(arr, k + 1, j, dp);
        ans = min(ans, subProblem + costOfPartition);
    }


    return dp[i][j] = ans;
}

//  Time: O(N^3)  Space: O(N^2) Memoized 2d Dp
int matrixMultiplication(vector<int> &arr, int n)
{
    vector<vector<int>> dp(n, vector<int> (n, -1));

    return solve(arr, 1, n - 1, dp);
}

// ------------------------------------------------------------------------



//  Time: O(N^3)  Space: O(N^2) Bottom up 2d Dp
int matrixMultiplication(vector<int> &arr, int n)
{
    vector<vector<int>> dp(n, vector<int> (n, 0));

    for (int d = 1; d <= n; d++) {

        for (int i = 1; i <= n - d - 1; i++) {
            int j = i + d;

            int ans = INT_MAX;
            for (int k = i; k < j; k++) {
                int costOfPartition = arr[i - 1] * arr[k] * arr[j];

                int subProblem = dp[i][k] + dp[k + 1][j];
                ans = min(ans, subProblem + costOfPartition);
            }

            dp[i][j] = ans;
        }
    }

    return dp[1][n - 1];
}


// -------------------------------------------------------------------------------

// striver

//  Time: O(N^3)  Space: O(N^2) Bottom up 2d Dp
int matrixMultiplication(vector<int> &arr, int n)
{
    vector<vector<int>> dp(n, vector<int> (n, 0));

    for (int i = n - 1; i >= 1; i--) {

        for (int j = i + 1; j <= n - 1; j++) {

            int ans = INT_MAX;
            for (int k = i; k < j; k++) {
                int costOfPartition = arr[i - 1] * arr[k] * arr[j];

                int subProblem = dp[i][k] + dp[k + 1][j];
                ans = min(ans, subProblem + costOfPartition);
            }

            dp[i][j] = ans;
        }
    }

    return dp[1][n - 1];
}
