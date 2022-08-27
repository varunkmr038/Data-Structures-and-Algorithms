int solve(vector<vector<int>>& triangle, int i, int j, vector<vector<int>>& dp) {

    int m = triangle.size(), n = triangle[i].size();

    if (i == m - 1) return triangle[i][j];
    if (dp[i][j] != -1) return dp[i][j];

    int goDown = solve(triangle, i + 1, j, dp);
    int goDiagonal = solve(triangle, i + 1, j + 1, dp);

    return dp[i][j] = min(goDown, goDiagonal) + triangle[i][j];
}

//  Time: O(N^2) Space: O(N^2) Memoized 2D Dp
int minimumTotal(vector<vector<int>>& triangle) {

    int m = triangle.size();

    vector<vector<int>> dp(m, vector<int>(m, -1));
    return solve(triangle, 0, 0, dp);

}

// -------------------------------------------------------------------------------




//  Time: O(N^2) Space: O(N^2) Bottom  Up 2D Dp
int minimumTotal(vector<vector<int>>& triangle) {

    int m = triangle.size();

    vector<vector<int>> dp(m + 1, vector<int>(m + 1, 0));

    for (int i = m - 1; i >= 0; i--) {
        for (int j = i; j >= 0; j--) {
            dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];
        }
    }
    return dp[0][0];
}


// -----------------------------------------------------------------------------------

//  Time: O(N^2) Space: O(N) Space Optimised Bottom  Up 1D Dp
int minimumTotal(vector<vector<int>>& triangle) {

    int m = triangle.size();

    vector<int> dp(m + 1, 0);

    for (int i = m - 1; i >= 0; i--) {

        vector<int> temp(m + 1, 0);
        for (int j = i; j >= 0; j--) {
            temp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];
        }

        for (int j = 0; j <= m; j++) dp[j] = temp[j];
    }
    return dp[0];
}
