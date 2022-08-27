int solve(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& dp) {

    int n = matrix.size();

    if (i == n - 1) return matrix[i][j];
    if (dp[i][j] != -1) return dp[i][j];

    int goLeftDown = INT_MAX, goDown = INT_MAX, goRightDown = INT_MAX;

    if (j > 0)
        goLeftDown = solve(matrix, i + 1, j - 1, dp);

    goDown = solve(matrix, i + 1, j , dp);

    if (j < n - 1)
        goRightDown = solve(matrix, i + 1, j + 1, dp);

    return dp[i][j] = min({goLeftDown, goDown, goRightDown}) + matrix[i][j];
}

//  Time: O(N^3) Space: O(N^2) Memoized 2D Dp
int minFallingPathSum(vector<vector<int>>& matrix) {

    int n = matrix.size();

    vector<vector<int>> dp(n, vector<int>(n, -1));

    int ans = INT_MAX;

    // itearte over first row ad find the falling path from each element
    // O(N)
    for (int i = 0; i < n; i++) {

        // O(N^2)
        ans  = min(ans, solve(matrix, 0, i, dp));

        fill(dp.begin(), dp.end(), vector<int>(n, -1));
    }

    return ans;
}

// -------------------------------------------------------------------------------


//  Time: O(N^2) Space: O(N^2) Bottom up 2D Dp
int minFallingPathSum(vector<vector<int>>& matrix) {

    int n = matrix.size();

    vector<vector<int>> dp(n, vector<int>(n, 0));

    // base case dp last row = matrix last row
    for (int i = 0; i < n; i++) dp[n - 1][i] = matrix[n - 1][i];

    for (int i = n - 2; i >= 0; i--) {

        for (int j = n - 1; j >= 0; j--) {
            int goLeftDown = INT_MAX, goDown = INT_MAX, goRightDown = INT_MAX;

            if (j > 0)
                goLeftDown = dp[i + 1][j - 1];

            goDown = dp[i + 1][j];

            if (j < n - 1)
                goRightDown = dp[i + 1][j + 1];

            dp[i][j] = min({goLeftDown, goDown, goRightDown}) + matrix[i][j];
        }

    }

    int ans = INT_MAX;
    for (int i = 0; i < n; i++) ans = min(ans, dp[0][i]);
    return ans;
}


// -------------------------------------------------------------------------------


//  Time: O(N^2) Space: O(N) Space Optimised 1D Dp
int minFallingPathSum(vector<vector<int>>& matrix) {

    int n = matrix.size();

    vector<int> dp(n, 0);

    // base case dp last row = matrix last row
    for (int i = 0; i < n; i++) dp[i] = matrix[n - 1][i];

    for (int i = n - 2; i >= 0; i--) {

        vector<int> temp(n);
        for (int j = n - 1; j >= 0; j--) {
            int goLeftDown = INT_MAX, goDown = INT_MAX, goRightDown = INT_MAX;

            if (j > 0)
                goLeftDown = dp[j - 1];

            goDown = dp[j];

            if (j < n - 1)
                goRightDown = dp[j + 1];

            temp[j] = min({goLeftDown, goDown, goRightDown}) + matrix[i][j];
        }

        for (int j = 0; j < n; j++) dp[j] = temp[j];
    }

    int ans = INT_MAX;
    for (int i = 0; i < n; i++) ans = min(ans, dp[i]);
    return ans;
}

